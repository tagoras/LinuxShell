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
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("mount", std::make_shared<Mount>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("mkdir", std::make_shared<Mkdir>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("id", std::make_shared<Id>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("setid", std::make_shared<Setid>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("stat", std::make_shared<Stat>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("chown", std::make_shared<Chown>()));
    commands.insert(std::pair<std::string, std::shared_ptr<ICommand>>("chgrp", std::make_shared<Chgrp>()));
}