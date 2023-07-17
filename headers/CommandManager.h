#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include <vector>
#include <string>
#include <map>
#include <memory>

#include "ErrorManager.h"
#include "ICommand.h"
#include "Echo.h"
#include "Cat.h"
#include "Cp.h"
#include "Cd.h"
#include "Ln.h"
#include "Mv.h"
#include "Rm.h"
#include "Umount.h"
#include "Mount.h"
#include "Mkdir.h"
#include "Id.h"
#include "Setid.h"
#include "Stat.h"
#include "Chown.h"
#include "Chgrp.h"
#include "Chmod.h"

// Class Used to keep all of the shell commands
class Command_Manager{
    public:
        std::map<std::string,std::shared_ptr<ICommand>> commands;
    public:
        Command_Manager();
};

#endif