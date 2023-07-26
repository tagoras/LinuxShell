#ifndef KILL_H
#define KILL_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Kill : public ICommand{
    public:
        int executeCommand(const std::vector<std::string> &args) const override;
};

#endif