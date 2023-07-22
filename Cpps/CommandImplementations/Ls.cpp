#include "../../headers/CommandHeaders/Ls.h"

#include <iostream>
#include <iomanip>

#include <dirent.h> // for opendir()
#include <sys/stat.h> // for stat()

int Ls::executeCommand(const std::vector<std::string> &args) const
{
    DIR *directory_stream;
    directory_stream = opendir(".");

    if(directory_stream == nullptr) return -1;

    struct dirent *next_entry;

    errno = 0;
    next_entry = readdir(directory_stream);

    if(next_entry == nullptr)
    {
        closedir(directory_stream);
        if(errno != 0) return -1;
        else return 0;
    }

    std::string file_name;
    bool isDirectory;
    int counter = 0;

    while(next_entry)
    {
        isDirectory = false;
        file_name = next_entry->d_name;
        
        if(file_name == "." || file_name == "..") {
            next_entry = readdir(directory_stream);
            continue;
        }

        else
        {
            // Find out if next entry is a directory
            struct stat entry_info;
            if(stat(file_name.c_str(), &entry_info) == -1)
            {
                // Ignore stat() and just assume that the entry is a simple file
            }
            else if(entry_info.st_mode & S_IFDIR)
            {
                std::cout << std::left << "\033[0;32m" << std::setw(13) << std::string(next_entry->d_name) << "\033[0m ";
            }
            else
            {
                std::cout << std::left << std::setw(13) << std::string(next_entry->d_name) << " ";
            }

            counter = (counter+1) % 8;
            if(!counter) std::cout << std::endl;
        }

        next_entry = readdir(directory_stream);        
    }

    if(closedir(directory_stream)==-1) return -1;

    return errno==0 ? 0 : -1;
}