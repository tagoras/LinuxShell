#ifndef TIME_H
#define TIME_H

#include <vector>
#include <string>

#include "../ICommand.h"

class Time : public ICommand{
    public:
        virtual int executeCommand(const std::vector<std::string>&) const;
        int timeEpoch() const;
        int timeSystem() const;
        int timeProcess() const;
};

#endif