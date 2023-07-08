#include "../headers/CommandManager.h"

Command_Manager::Command_Manager()
{
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("echo", std::make_shared<Echo>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("cat", std::make_shared<Cat>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("cp", std::make_shared<Cp>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("cd", std::make_shared<Cd>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("ln", std::make_shared<Ln>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("mv", std::make_shared<Mv>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("rm", std::make_shared<Rm>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("umount", std::make_shared<Umount>()));
}