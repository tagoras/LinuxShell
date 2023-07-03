#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include <vector>
#include <string>
#include <map>
#include <memory>

#include "ICommand.h"
#include "Echo.h"

// Class Used to keep all of the shell commands
class Command_Manager{
    public:
        std::map<std::string,std::shared_ptr<ICommand>> commands;
    public:
        Command_Manager();
};

Command_Manager::Command_Manager()
{
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("echo", std::make_shared<Echo>()));
}

#endif