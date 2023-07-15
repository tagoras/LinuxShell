#include "../headers/Setid.h"

#include <unistd.h>
#include <sys/fsuid.h>

int Setid::executeCommand(const std::vector<std::string> &args) const
{
    if(args.size()==2 && args[0]=="-u")
    {
        return setuid(static_cast<uid_t>(std::stoi(args[1])));
    }
    else if(args.size()==2 && args[0]=="-g")
    {
        return setgid(static_cast<gid_t>(std::stoi(args[1])));
    }
    else if(args.size()==3 && args[0]=="-u")
    {
        return setreuid(static_cast<uid_t>(std::stoi(args[1])), static_cast<uid_t>(std::stoi(args[2])));
    }
    else if(args.size()==3 && args[0]=="-g")
    {
        return setregid(static_cast<uid_t>(std::stoi(args[1])), static_cast<uid_t>(std::stoi(args[2])));
    }
    else if(args.size()==4 && args[0]=="-u")
    {
        return setresuid(static_cast<uid_t>(std::stoi(args[1])), static_cast<uid_t>(std::stoi(args[2])), static_cast<uid_t>(std::stoi(args[3])));
    }
    else if(args.size()==4 && args[0]=="-g")
    {
        return setresgid(static_cast<uid_t>(std::stoi(args[1])), static_cast<uid_t>(std::stoi(args[2])), static_cast<uid_t>(std::stoi(args[3])));
    }
    else if(args.size()==1 && args[0]=="-fu")
    {
        return setfsuid(static_cast<uid_t>(std::stoi(args[1])));
    }
    else if(args.size()==1 && args[0]=="-fg")
    {
        return setfsgid(static_cast<uid_t>(std::stoi(args[1])));
    }
    return -1;
}