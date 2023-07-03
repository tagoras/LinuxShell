#include "../headers/Cat.h"

#include <fcntl.h> // for open()
#include <unistd.h> // for read(), write()

#define BUFSIZE 4096

int Cat::executeCommand(const std::vector<std::string> &args) const
{
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