#include "../../headers/CommandHeaders/Stat.h"

#include <sys/stat.h> // for stat(), lstat(), fstat()

#include <iostream>
#include <iomanip> // for std:setw()

int Stat::executeCommand(const std::vector<std::string> &args) const {
    /*First retrieve file status buffer*/
    struct stat buffer;
    int op_res;
    if(args[0]=="-l")
    {
        op_res = lstat(args[1].c_str(), &buffer);
    }
    else
    {
        op_res = stat(args[0].c_str(), &buffer);
    }

    if(op_res) return op_res;

    /*Print out the file information*/
    std::cout << std::left << std::setw(20) << "Device:" << buffer.st_dev << "\n";

    switch(buffer.st_mode & S_IFMT)
    {
        case S_IFREG: std::cout << std::setw(20) << "File Type:" << "Regular file\n"; break;
        case S_IFDIR: std::cout << std::setw(20) << "File Type:" << "Directory\n"; break;
        case S_IFCHR: std::cout << std::setw(20) << "File Type:" << "Character Device\n"; break;
        case S_IFBLK: std::cout << std::setw(20) << "File Type:" << "Block device\n"; break;
        case S_IFLNK: std::cout << std::setw(20) << "File Type:" << "Symbolic Link\n"; break;
        case S_IFIFO: std::cout << std::setw(20) << "File Type:" << "FIFO or Pipe\n"; break;
        case S_IFSOCK: std::cout << std::setw(20) << "File Type:" << "Socket\n"; break;
        default: std::cout << std::setw(20) << "File Type:" << "Unknown file type\n"; break;
    }

    std::cout << std::setw(20) << "User:" << buffer.st_uid << "\n";
    std::cout << std::setw(20) << "Group:" << buffer.st_gid << "\n";
    std::cout << std::setw(20) << "Hard Links:" << buffer.st_nlink << "\n";
    std::cout << std::setw(20) << "Block size:" << buffer.st_blksize << "\n";
    std::cout << std::setw(20) << "Blocks allocated:" << buffer.st_blocks << "\n";
    std::cout << std::setw(20) << "Last access time:" << buffer.st_atim.tv_sec << "\n";
    std::cout << std::setw(20) << "Last modification time:" << buffer.st_mtim.tv_sec << "\n";
    std::cout << std::setw(20) << "Last status change:" << buffer.st_ctim.tv_sec << "\n";

    return 0;

}