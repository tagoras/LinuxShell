#include "../../headers/CommandHeaders/Pid.h"

#include <unistd.h>
#include <iostream>

int Pid::executeCommand(const std::vector<std::string> &args) const
{
    std::cout << getpid();
    return 0;
}