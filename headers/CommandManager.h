#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include <vector>
#include <string>
#include <map>
#include <memory>

#include "ICommand.h"
#include "Echo.h"
#include "Cat.h"
#include "Cp.h"

// Class Used to keep all of the shell commands
class Command_Manager{
    public:
        std::map<std::string,std::shared_ptr<ICommand>> commands;
    public:
        Command_Manager();
};

#endif