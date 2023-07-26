#include "../../headers/CommandHeaders/Kill.h"

#include <signal.h>

int Kill::executeCommand(const std::vector<std::string> &args) const
{
    return kill(std::stoi(args[0]), std::stoi(args[1]));
}