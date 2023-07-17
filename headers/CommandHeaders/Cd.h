#ifndef CD_H
#define CD_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Cd : public ICommand{
    public:
        int executeCommand(const std::vector<std::string>&) const override;
};

#endif