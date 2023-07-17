#include "../../headers/CommandHeaders/Cat.h"

#include <fcntl.h> // for open()
#include <unistd.h> // for read(), write()
#include <limits.h> // PATH_MAX

#define BUFSIZE 4096

int Cat::executeCommand(const std::vector<std::string> &args) const
{
    /*
        Handle the case where the filepath is a symbolic link and -L is specified
    */

    if(args[0] == "-L")
    {
        char symbolicLinkContent[PATH_MAX];
        ssize_t bytes_in_buf = readlink(args[1].c_str(), symbolicLinkContent, PATH_MAX);
        size_t bytes_written = write(STDOUT_FILENO, symbolicLinkContent, bytes_in_buf);

        if(bytes_written != bytes_in_buf) return -1;
        else return 0;
    }

    int file_descriptor = open(args[0].c_str(), O_RDONLY);
    if(file_descriptor==-1)
    {
        /*Handle an error as you like*/
        return -1;
    }
    else
    {
        char buf[BUFSIZE];
        ssize_t bytes_read;
        ssize_t bytes_written;

        do{
            bytes_read = read(file_descriptor, &buf, BUFSIZE-1);
            if(bytes_read<=0)
            {
                //Handle EOF or Error while reading from the file
                if(bytes_read==-1)
                {
                    close(file_descriptor);
                    return -1;
                }
                break;
            }
            else
            {
                buf[bytes_read] = '\0';
                bytes_written = write(STDOUT_FILENO, &buf, bytes_read);

                if(bytes_written != bytes_read)
                {
                    // Bad or partially bad write
                    close(file_descriptor);
                    return -1;
                }
            }
        }while(bytes_read>0);
        close(file_descriptor);
        return 0;
    }
}