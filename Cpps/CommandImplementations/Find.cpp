#include "../../headers/CommandHeaders/Find.h"

#include <unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/stat.h>
#include <iostream>

#include <deque>

/*
    ALMOST WORKING, NEED TO FIX Find::thread_function() as it's path string creation is not working if, lets say, we start from the /
*/

class thread_data{
    public:
        // Target is used to search for a file but also to store a file_path if the file was found
        std::string target;
        std::string path;
        std::vector<std::string> unchecked_directories;
        // tread_id is used when creating and joining threads
        pthread_t thread_id;
};


pthread_mutex_t pool_lock = PTHREAD_MUTEX_INITIALIZER;
std::vector<thread_data *> unjoined_threads;

std::vector<thread_data *> idle_threads;

pthread_cond_t cond_thread_died = PTHREAD_COND_INITIALIZER;

int Find::executeCommand(const std::vector<std::string> &args) const
{
    std::vector<std::string> unchecked_directories;
    unchecked_directories.push_back(args[1]);

    // Find out how many cores we have and initialise pool of that many cores
    int num_cores = sysconf(_SC_NPROCESSORS_ONLN)-1;

    thread_data *threads = new thread_data[num_cores];

    for(int i=0;i<num_cores;++i){threads[i].target=args[0];}

    for(int i=0;i<num_cores;++i) idle_threads.push_back(&threads[i]);

    for(;;)
    {
        pthread_mutex_lock(&pool_lock);

        while(idle_threads.size()==0 && unjoined_threads.size()==0)
        {
            pthread_cond_wait(&cond_thread_died, &pool_lock);
        }

        // Start by analysing unjoined threads and adding them to idle threads.
        for(auto *thread : unjoined_threads)
        {
            if(thread->target != args[0])
            {
                std::cout << thread->target;
                std::cout << std::flush;
                delete[] threads;
                return 0;
            }
            for(const auto dir : thread->unchecked_directories) unchecked_directories.push_back(dir);

            thread->unchecked_directories.clear();

            idle_threads.push_back(thread);
        }

        // Since all the unjoined threads have been analysed we can clear the vector
        unjoined_threads.clear();

        // Now create a working thread for every unchecked directory, but prior to that, check if uncheck_directories has something in it
        // If they do not, then we will have to sleep again. Additionally, if idle_threads == num_cores AND we have no directories left than the file
        // Could not be found
        if(idle_threads.size()==num_cores && unchecked_directories.size()==0)
        {
            std::cout << "Could not find" << std::endl;
            return -1;
        }

        // Keep issuing new threads for each directory until either runs out
        while(unchecked_directories.size() && idle_threads.size())
        {
            thread_data *new_thread_data = idle_threads.back();
            idle_threads.pop_back();

            new_thread_data->path = unchecked_directories.back();
            unchecked_directories.pop_back();

            pthread_create(&new_thread_data->thread_id, nullptr, Find::thread_function, new_thread_data);
        }

        pthread_mutex_unlock(&pool_lock);
    }
    return 0;
}

void* Find::thread_function(void *data_pointer)
{
    pthread_detach(pthread_self());
    struct thread_data *data = static_cast<thread_data *>(data_pointer);

    DIR *directory_stream = opendir(data->path.c_str());

    // If this directory could not be opened for some reason, then finish the thread
    if(directory_stream==nullptr)
    {
        return nullptr;
    }

    dirent *entry;
    std::string current_entry_path;
    struct stat file_information_buffer;

    while(entry=readdir(directory_stream))
    {
        if(std::string(entry->d_name)=="." || std::string(entry->d_name)=="..") continue;

        current_entry_path = data->path + "/" + std::string(entry->d_name);
        // Check if the name of the entry matches the target and if so, terminate after setting the target field
        if(std::string(entry->d_name)==data->target)
        {
            data->target=current_entry_path;
            break;
        }
        else
        {
            // If no match, inspect the entry and if it is a directory add the path of the directory to the unchecked_directories
            if(stat(current_entry_path.c_str(), &file_information_buffer))
            {
                // Error while retrieving information about the file. I choose to skip over it.
                continue;
            }
            else
            {
                // Else we retrieved the I-Node information so we can find out if the entry is a directory or not
                if(S_ISDIR(file_information_buffer.st_mode))
                {
                    // Is a directory, add to the list of directories
                    data->unchecked_directories.push_back(current_entry_path);
                }
                else
                {
                    // Otherwise it is not a directory and we already know that it is not a match, so we can continue
                    continue;
                }
            }
        }
    }

    

    pthread_mutex_lock(&pool_lock);
    unjoined_threads.push_back(data);
    pthread_mutex_unlock(&pool_lock);
    pthread_cond_signal(&cond_thread_died);

    return nullptr;
}
