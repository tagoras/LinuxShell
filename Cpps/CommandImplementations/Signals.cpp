#include "../../headers/CommandHeaders/Signals.h"
#include "../../headers/UtilityFunctions.h"

#include <signal.h>

#include <string.h> // for strsignal()
#include <iostream>

int Signals::executeCommand(const std::vector<std::string> &args) const
{
    if(args[0]=="--ADD" || args[0]=="-A") return addToProcessMask(args);
    else if(args[0]=="--REMOVE" || args[0]=="-R") return removeFromProcessMask(args);
    else if(args[0]=="--PRINT" || args[0]=="-P") return printSignalMask(args);
    else return -1;
}

int Signals::addToProcessMask(const std::vector<std::string> &args) const
{
    sigset_t new_signals, current_mask;

    if(sigprocmask(SIG_BLOCK, nullptr, &current_mask) != 0)
    {
        return -1;
    }

    sigemptyset(&new_signals);
    int sig;

    for(int i=1; i<args.size();++i)
    {
        sig = stringToSignal(args[i]);
        if(sig==-1)
        {
            return -1;
        }
        if(sigaddset(&new_signals, sig)==-1)
        {
            // Revert changes made to process's signal mask
            if(sigprocmask(SIG_SETMASK, &current_mask, nullptr)==-1)
            {
                // Could not reset processe's signal mask, don't know what handling to do for it now
            }
            return -1;
        }
    }

    if(sigprocmask(SIG_BLOCK, &new_signals, nullptr)==-1)
    {
        return -1;
    }

    return 0;
}

int Signals::removeFromProcessMask(const std::vector<std::string> &args) const
{
    sigset_t current_mask, backup_mask;
    if(sigprocmask(SIG_BLOCK, nullptr, &current_mask) != 0)
    {
        // could not retrieve process signal mask
        return -1;
    }

    backup_mask = current_mask;
    int sig;

    for(const auto &arg : args)
    {
        sig = stringToSignal(arg);
        if(sigdelset(&current_mask, sig)==-1)
        {
            if(sigprocmask(SIG_SETMASK, &backup_mask, nullptr)==-1)
            {
                // Could not reset processe's signal mask, don't know what handling to do for now
            }
            return -1;
        }
    }
    return 0;
}

int Signals::printSignalMask(const std::vector<std::string> &args) const
{
    sigset_t current_mask;
    if(sigprocmask(SIG_BLOCK, nullptr, &current_mask) != 0)
    {
        // could not retrieve process signal mask
        return -1;
    }

    std::cout << "Here are the signals that are currently blocked:";

    for(int i=0;i<NSIG; ++i)
    {
        if(sigismember(&current_mask, i)==1)
        {
            std::string signal_description=strsignal(i);
            std::cout << "\n" <<signal_description;
        }
    }
    return 0;
}