#ifndef UMOUNT_H
#define UMOUNT_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Umount : public ICommand{
    public:
        int executeCommand(const std::vector<std::string>&) const override;
};

#endif