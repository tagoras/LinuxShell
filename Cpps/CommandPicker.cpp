#include "../headers/CommandPicker.h"

std::shared_ptr<ICommand> CommandPicker::pick_command(const std::string &name) const
{
    return command_manager.commands.at(name);
}