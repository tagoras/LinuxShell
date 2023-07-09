#include "../headers/Mount.h"

#include <sys/mount.h>

int Mount::executeCommand(const std::vector<std::string> &args) const
{
    return mount(args[0].c_str(), args[1].c_str(), args[2].c_str(), 0, NULL);
}