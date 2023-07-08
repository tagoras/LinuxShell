#include "../headers/Mv.h"

#include <stdio.h>

int Mv::executeCommand(const std::vector<std::string> &args) const
{
    // TODO:
    // Add the functionality of moving files between different files systems
    // Error handling?
    return rename(args[0].c_str(), args[1].c_str());
}