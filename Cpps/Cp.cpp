

#include "../headers/Cp.h"

#include <fcntl.h> // for open()
#include <unistd.h> // for read(), write()
#define BUF_SIZE 8096

int Cp::executeCommand(const std::vector<std::string> &args) const
{
    int read_from_fd;
    int write_to_fd;

    read_from_fd = open(args[0].c_str(), O_RDONLY);
    write_to_fd = open(args[1].c_str(), O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);

    if(read_from_fd==-1)
    {
        // Handle error while opening file at args[0]
        return -1;
    }

    if(write_to_fd==-1)
    {
        // Handle error while opening file at args[0]
        return -1;
    }

    char buf[BUF_SIZE];
    ssize_t bytes_read;
    ssize_t bytes_written;

    bytes_read = read(read_from_fd, &buf, BUF_SIZE-1);
    while(bytes_read>0)
    {
        buf[bytes_read] = '\0';
        bytes_written = write(write_to_fd, buf, bytes_read);
        if(bytes_written != bytes_read)
        {
            // Handling errors
            if(bytes_written == -1)
            {
                // Error while writing to the file
                close(read_from_fd);
                close(write_to_fd);
                return -1;
            }
            else
            {
                // Partial/Incomplete write
                close(read_from_fd);
                close(write_to_fd);
                return -1;
            }
        }
        bytes_read = read(read_from_fd, &buf, BUF_SIZE-1);
    }
    close(read_from_fd);
    close(write_to_fd);
    return 0;
}