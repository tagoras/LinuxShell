#ifndef CHOWN_H
#define CHOWN_H

#include "../ICommand.h"
#include <string>
#include <vector>

class Chown : public ICommand{
    int executeCommand(const std::vector<std::string> &args) const override;
};

#endif