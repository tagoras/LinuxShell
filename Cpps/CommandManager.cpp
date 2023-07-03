#include "../headers/CommandManager.h"

Command_Manager::Command_Manager()
{
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("echo", std::make_shared<Echo>()));
}