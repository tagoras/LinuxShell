#ifndef SUICIDE_H
#define SUICIDE_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Suicide : public ICommand{
    public:
        int executeCommand(const std::vector<std::string> &args) const override;
        int setTimer(const std::vector<std::string> &args) const;
        int getTimer(const std::vector<std::string> &args) const;
};

#endif