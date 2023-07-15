#ifndef SETID_H
#define SETID_H

#include "ICommand.h"

#include <vector>
#include <string>

class Setid : public ICommand{
    public:
        int executeCommand(const std::vector<std::string>&) const override;
};

#endif