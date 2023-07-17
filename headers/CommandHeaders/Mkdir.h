#ifndef MKDIR_H
#define MKDIR_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Mkdir : public ICommand{
    public:
        int executeCommand(const std::vector<std::string> &args) const override;
        int commandOptionMode(const std::vector<std::string> &args) const;
};

#endif