#include "../headers/CommandManager.h"

Command_Manager::Command_Manager()
{
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("echo", std::make_shared<Echo>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("cat", std::make_shared<Cat>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("cp", std::make_shared<Cp>()));
}