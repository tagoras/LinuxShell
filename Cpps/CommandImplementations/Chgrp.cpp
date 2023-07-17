#include "../../headers/CommandHeaders/Chgrp.h"
#include <unistd.h> // for chown()
#include "../../headers/UtilityFunctions.h"

int Chgrp::executeCommand(const std::vector<std::string> &args) const 
{
    return chown(args[1].c_str(), -1, groupname_to_id(args[0]));
}