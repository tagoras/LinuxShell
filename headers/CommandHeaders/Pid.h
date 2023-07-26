#ifndef PID_H
#define PID_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Pid : public ICommand{
    public:
        int executeCommand(const std::vector<std::string> &args) const override;
};

#endif