#include "../../headers/CommandHeaders/Rm.h"

#include <unistd.h> // for unlink()

int Rm::executeCommand(const std::vector<std::string> &args) const {
    return unlink(args[0].c_str());
}