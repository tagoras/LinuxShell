#ifndef MV_H
#define MV_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Mv : public ICommand{
    public:
        int executeCommand(const std::vector<std::string>&) const override;
};

#endif