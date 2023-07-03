#ifndef ECHO_H
#define ECHO_H

#include "ICommand.h"

#include <vector>
#include <string>

#include <fcntl.h>
#include <unistd.h>

class Echo : public ICommand{
    public:
        int executeCommand(std::vector<std::string>) const override;
};

int Echo::executeCommand(std::vector<std::string> args) const {
    for(std::string arg : args)
    {
        if(write(STDIN_FILENO, arg.c_str(), sizeof(arg.c_str())) != sizeof(arg.c_str())) return -1;
    }
    return 0;
}

#endif