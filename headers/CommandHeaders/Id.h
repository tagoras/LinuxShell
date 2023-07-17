#ifndef ID_H
#define ID_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Id : public ICommand{
    public:
        int executeCommand(const std::vector<std::string> &args) const override;
};

#endif