#ifndef ICOMMAND
#define ICOMMAND

#include <vector>
#include <string>

class ICommand{
    public:
        virtual int executeCommand(std::vector<std::string>)=0;
};

#endif