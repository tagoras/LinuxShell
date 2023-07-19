#ifndef SLEEP_H
#define SLEEP_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Sleep : public ICommand{
    public:
        int executeCommand(const std::vector<std::string>&) const override;
};

#endif