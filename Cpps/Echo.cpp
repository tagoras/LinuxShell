
#include "../headers/Echo.h"

int Echo::executeCommand(std::vector<std::string> args) const {
    for(std::string arg : args)
    {
        if(write(STDIN_FILENO, arg.c_str(), sizeof(arg.c_str())) != sizeof(arg.c_str())) return -1;
    }
    return 0;
}