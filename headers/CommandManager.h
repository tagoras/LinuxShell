#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include <vector>
#include <string>

#include "ICommand.h"

// Class Used to keep all of the shell commands
class Command_Manager{
    private:
        std::vector<ICommand> commands;
    public:
        Command_Manager();
};

#endif