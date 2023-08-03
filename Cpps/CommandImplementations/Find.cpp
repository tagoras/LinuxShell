#include "../../headers/CommandHeaders/Find.h"

#include <unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/stat.h>
#include <iostream>

#include <deque>

/*
    THIS IS NOT CURRENTLY WORKING AND HAS LOADS OF THREAD SYNCHRONIZATION ISSUES. TO BE FIXED
*/

pthread_mutex_t thread_access = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t thread_died = PTHREAD_COND_INITIALIZER;

int dead_threads;

class thread_data{
    public:
        // Target is used to search for a file but also to store a file_path if the file was found
        std::string target;
        std::string path;
        std::vector<std::string> unchecked_directories;
        // tread_id is used when creating and joining threads
        pthread_t thread_id;
        // The following are used to mark that the data structure is associated with a thread that has finished its execution
        pthread_mutex_t status_lock;
        bool isFinished;
    public:
        thread_data() {pthread_mutex_init(&status_lock, nullptr);}
        ~thread_data(){pthread_mutex_destroy(&status_lock);}
};

int Find::executeCommand(const std::vector<std::string> &args) const
{
    std::vector<std::string> unchecked_directories;

    // Find out how many cores we have and initialise pool of that many cores (minus one for managing thread)
    int num_cores = sysconf(_SC_NPROCESSORS_ONLN)-1;

    dead_threads = num_cores;

    thread_data *threads = new thread_data[num_cores];

    for(int i=0;i<num_cores;++i){threads[i].target=args[0];}
    // Lets use one thread to go through initial directories
    pthread_create(&threads->thread_id,nullptr, Find::thread_function, threads);
    pthread_join(threads->thread_id, nullptr);

    // Analyse results, if target was not found we can start utilising multiple threads

    if(threads[0].target!=args[0])
    {
        std::cout << threads[0].target;
        delete[] threads;
        return 0;
    }

    // Otherwise add unchecked directories to the vector
    for(const auto dir : threads[0].unchecked_directories)
    {
        unchecked_directories.push_back(dir);
    }
    std::cout << unchecked_directories.size() << std::endl;

    // And now start to utilise threads
    // Start with initializing per-thread structures, subject for removing if: new thread_data[num_cores]{args[0]}; works as expected
    for(int i=0;i<num_cores;++i)
    {
        threads[i].target=args[0];
    }

    for(;;)
    {
        pthread_mutex_lock(&thread_access);
        while(dead_threads==0)
        {
            // following function call atomically unlocks thread_access and then sleeps until thread_died is notified
            pthread_cond_wait(&thread_died, &thread_access);
            // After return, we have a lock on thread_access
        }

        // We will be giving work to threads until no more threads are left or until we have no unchecked directories
        int index = 0;
        while(dead_threads && index<num_cores && unchecked_directories.size())
        {
            pthread_mutex_lock(&threads[index].status_lock);
            if(threads[index].isFinished)
            {
                // Reset the flag for future use of the structure and release the lock
                threads[index].isFinished=false;
                pthread_mutex_unlock(&threads[index].status_lock);

                // Let us first check if the target string was changed, which would indicate that path was found and we need to stop searching
                if(threads[index].target!=args[0])
                {
                    std::cout << threads[index].target;
                    // TODO: FIX MEMORY LEAK.
                    return 0;
                }

                for(auto dir_path : threads[index].unchecked_directories)
                {
                    unchecked_directories.push_back(dir_path);
                }

                threads[index].unchecked_directories.clear();

                // This thread has finished its execution, meaning we can assign a new directory to it
                threads[index].path = unchecked_directories.back();
                unchecked_directories.pop_back();
                
                // Now initiate a thread and reduce the number of dead threads
                pthread_create(&threads[index].thread_id, nullptr, Find::thread_function, &threads[index]);
                --dead_threads;
            }
            ++index;
        }

        pthread_mutex_unlock(&thread_access);
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
        // Check if the name of the entry matches  the target and if so, terminate after setting the target field
        if(std::string(entry->d_name)==data->target)
        {
            data->target = current_entry_path;
            closedir(directory_stream);
            
            pthread_mutex_lock(&thread_access);
            ++dead_threads;
            pthread_mutex_unlock(&thread_access);

            return nullptr;
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

    pthread_mutex_lock(&thread_access);
    ++dead_threads;
    pthread_mutex_unlock(&thread_access);
    pthread_cond_signal(&thread_died);

    return nullptr;
}
