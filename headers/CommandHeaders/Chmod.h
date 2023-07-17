#ifndef CHMOD_H
#define CHMOD_H

#include "../ICommand.h"
#include <string>
#include <vector>

class Chmod : public ICommand{
    int executeCommand(const std::vector<std::string> &args) const override;
};

#endif