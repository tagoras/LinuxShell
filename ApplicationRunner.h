#ifndef APPLICATION_RUNNER
#define APPLICATION_RUNNER

#include "CommandParser.h"

class Application_Runner{
    private:
        CommandParser command_parser;
    public:
        Application_Runner() = default;
        void run() const;
};

#endif