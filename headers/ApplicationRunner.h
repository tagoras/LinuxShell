#ifndef APPLICATION_RUNNER
#define APPLICATION_RUNNER

#include "CommandParser.h"
#include "CommandPicker.h"

class Application_Runner{
    private:
        CommandParser command_parser; 
        CommandPicker command_picker;
        ErrorManager error_manager;
    public:
        Application_Runner() = default;
        void run() const;
};

#endif