#ifndef RUN_H
#define RUN_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Run : public ICommand{
    public:
        virtual int executeCommand(const std::vector<std::string> &args) const override;
};

#endif