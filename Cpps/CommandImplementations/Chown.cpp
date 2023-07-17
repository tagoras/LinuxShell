#include "../../headers/CommandHeaders/Chown.h"
#include <unistd.h> // for chown()
#include "../../headers/UtilityFunctions.h"

int Chown::executeCommand(const std::vector<std::string> &args) const 
{
    return chown(args[1].c_str(), username_to_id(args[0]), -1);
}