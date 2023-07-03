
#include "../headers/Echo.h"

int Echo::executeCommand(const std::vector<std::string> &args) const {
    for(std::string arg : args)
    {
        arg+=" ";
        if(write(STDOUT_FILENO, arg.c_str(), arg.size()) != arg.size()) return -1;
    }
    return 0;
}