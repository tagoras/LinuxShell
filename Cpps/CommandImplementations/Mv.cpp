#include "../../headers/CommandHeaders/Mv.h"

#include <stdio.h> // for rename()
#include <fcntl.h>
#include <sys/stat.h> // for stat()
#include <unistd.h> // for read(), write(), close()

int Mv::executeCommand(const std::vector<std::string> &args) const
{
    // If the file is on the same file system then just change directory entries
    if(rename(args[0].c_str(), args[1].c_str()) == 0) return 0;
    else
    {   
        // Trying to move a file to a different file system
        if(errno==EXDEV)
        {
            // Retrieve the permission flags from the old file
            struct stat old_file_data;
            mode_t permissions;

            if(stat(args[0].c_str(), &old_file_data) == -1)
            {
                // Error while retrieving permission data from the old file
                permissions = S_IRWXU;
            }

            else
            {
                permissions = old_file_data.st_mode & (S_IRWXU | S_IRWXG | S_IRWXU);
            }

            //Create the file in the different file system
            int new_file_descriptor;
            new_file_descriptor = open(args[1].c_str(), O_CREAT | O_WRONLY, permissions);

            if(new_file_descriptor==-1) return -1;

            int old_file_descriptor;
            old_file_descriptor = open(args[0].c_str(), O_RDONLY);

            if(old_file_descriptor==-1) return -1;

            char buf[BUFSIZ];
            size_t bytes_read, bytes_written;

            while(bytes_read=read(old_file_descriptor, buf, BUFSIZ)>0)
            {
                bytes_written = write(new_file_descriptor, buf, bytes_written);
                // Handle partial write
                if(bytes_written != bytes_read)
                {
                    close(old_file_descriptor);
                    close(new_file_descriptor);
                    
                    // Try and remove the new file from the file system
                    if(unlink(args[1].c_str())==-1)
                    {
                        // Error while removing a newly created file when a partial write happens
                        return -1;
                    }

                    return -1;
                }
            }
            // In case of bad read, just close file descriptors and remove the new file from the file system
            close(old_file_descriptor);
            close(new_file_descriptor);
            
            if(bytes_read < 0)
            {
                // Try and remove the new file from the file system
                if(unlink(args[1].c_str())==-1)
                {
                    // Error while removing a newly created file when a partial write happens
                    return -1;
                }
            }

            return 0;
        }
        else return -1;
    }
}