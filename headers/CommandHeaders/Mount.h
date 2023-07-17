#ifndef MOUNT_H
#define MOUNT_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Mount : public ICommand{
    public:
        int executeCommand(const std::vector<std::string>&) const override;
};

#endif