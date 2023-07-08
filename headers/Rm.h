#ifndef RM_H
#define RM_H

#include "ICommand.h"

#include <vector>
#include <string>

class Rm : public ICommand{
    public:
        int executeCommand(const std::vector<std::string>&) const override;
};

#endif