#include "../headers/Umount.h"

#include <sys/mount.h>

int Umount::executeCommand(const std::vector<std::string> &args) const {
    return umount2(args[0].c_str(), MNT_DETACH);
}