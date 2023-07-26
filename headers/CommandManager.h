#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include <vector>
#include <string>
#include <map>
#include <memory>

#include "ErrorManager.h"
#include "ICommand.h"
#include "./CommandHeaders/Echo.h"
#include "./CommandHeaders/Cat.h"
#include "./CommandHeaders/Cp.h"
#include "./CommandHeaders/Cd.h"
#include "./CommandHeaders/Ln.h"
#include "./CommandHeaders/Mv.h"
#include "./CommandHeaders/Rm.h"
#include "./CommandHeaders/Umount.h"
#include "./CommandHeaders/Mount.h"
#include "./CommandHeaders/Mkdir.h"
#include "./CommandHeaders/Id.h"
#include "./CommandHeaders/Setid.h"
#include "./CommandHeaders/Stat.h"
#include "./CommandHeaders/Chown.h"
#include "./CommandHeaders/Chgrp.h"
#include "./CommandHeaders/Chmod.h"
#include "./CommandHeaders/Time.h"
#include "./CommandHeaders/Suicide.h"
#include "./CommandHeaders/Sleep.h"
#include "./CommandHeaders/Ls.h"
#include "./CommandHeaders/Kill.h"
#include "./CommandHeaders/Pid.h"
#include "./CommandHeaders/Signals.h"
#include "./CommandHeaders/Run.h"

// Class Used to keep all of the shell commands
class Command_Manager{
    public:
        std::map<std::string,std::shared_ptr<ICommand>> commands;
    public:
        Command_Manager();
};

#endif