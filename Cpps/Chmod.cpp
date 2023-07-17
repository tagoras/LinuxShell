#include "../headers/Chmod.h"
#include <sys/stat.h> // for chmod()

int Chmod::executeCommand(const std::vector<std::string> &args) const {
    return chmod(args[1].c_str(), std::stoi(args[0]));
}