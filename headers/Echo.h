#ifndef ECHO_H
#define ECHO_H

#include "ICommand.h"

#include <vector>
#include <string>

#include <fcntl.h>
#include <unistd.h>

class Echo : public ICommand{
    public:
        int executeCommand(std::vector<std::string>) const override;
};

#endif