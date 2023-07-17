#ifndef STAT_H
#define STAT_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Stat : public ICommand{
    public:
        int executeCommand(const std::vector<std::string> &args) const override;
};

#endif