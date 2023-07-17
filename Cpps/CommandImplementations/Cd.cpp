

#include "../../headers/CommandHeaders/Cd.h"

#include <unistd.h> // for chdir(const char *pathname)

int Cd::executeCommand(const std::vector<std::string>&args) const
{
    return chdir(args[0].c_str());
}