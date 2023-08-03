#include "../headers/CommandLogger.h"

#include <string>

#include <fcntl.h>
#include <unistd.h>
#include <time.h>

void* CommandLogger::logToFile(void *arg)
{
    static const std::string file_name{"log.txt"};
    std::string *p = static_cast<std::string *>(arg);
    std::string command{*p + "\n"};
    
    int log_descriptor;
    log_descriptor = open(file_name.c_str(), O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH);

    if(log_descriptor == -1)
    {
        return nullptr;
    }

    time_t secs_since_epoch = time(nullptr);
    char *t = ctime(&secs_since_epoch);

    if(t==nullptr) return nullptr;

    std::string time_string{t};

    time_string = time_string.substr(0, time_string.length()-1);

    // Remove newline from time_string

    time_string += ": ";

    ssize_t bytes_written;
    bytes_written = write(log_descriptor, time_string.c_str(), time_string.size());
    bytes_written = write(log_descriptor, command.c_str(), command.size());

    close(log_descriptor);

    return nullptr;
}