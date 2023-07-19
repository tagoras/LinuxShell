#ifndef LS_H
#define LS_H

#include "../ICommand.h"

#include <map>
#include <string>
#include <vector>

// This class is used to retrieve the command name from the shell
class Ls : public ICommand{
    public:
        int executeCommand(const std::vector<std::string> &args) const override;
};

#endif