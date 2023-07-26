#include "../headers/SignalHandler.h"

#include <signal.h>

#include "../headers/UtilityFunctions.h"

SignalHandler::SignalHandler()
{
    addHandlers();
}

void SignalHandler::addHandlers() const
{
    // Testing some fancy c++ features
    auto response = signal(SIGKILL, sureKillHandler);
    if(response == SIG_ERR)
    {
        // Handle error to log file?
    }
}