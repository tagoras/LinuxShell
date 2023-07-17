

#include "../../headers/CommandHeaders/Mkdir.h"

#include <sys/stat.h> // for mkdir()


int Mkdir::executeCommand(const std::vector<std::string> &args) const
{
    if(args[0]=="-m" || args[0]=="--mode") return commandOptionMode(args);
    else return -1;
}

int Mkdir::commandOptionMode(const std::vector<std::string> &args) const
{
    mode_t permissions = std::stoi(args[1], nullptr, 8);
    return mkdir(args[2].c_str(), permissions);
}