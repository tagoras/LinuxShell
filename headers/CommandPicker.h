#ifndef COMMAND_PICKER
#define COMMAND_PICKER

#include <string>
#include <memory>

#include "CommandManager.h"
#include "ICommand.h"

class CommandPicker{
    private:
        Command_Manager command_manager;
    public:
        CommandPicker()=default;
        std::shared_ptr<ICommand> pick_command(const std::string &name) const;
};

#endif