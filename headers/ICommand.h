#ifndef ICOMMAND
#define ICOMMAND

#include <vector>
#include <string>

class ICommand{
    public:
        virtual int executeCommand(const std::vector<std::string>&)const=0;
};

#endif