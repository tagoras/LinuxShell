#ifndef SIGNALS_H
#define SIGNALS_H

#include "../ICommand.h"

#include <vector>
#include <string>

class Signals : public ICommand{
    public:
        virtual int executeCommand(const std::vector<std::string> &args) const override;
    private:
        int addToProcessMask(const std::vector<std::string> &args) const;
        int removeFromProcessMask(const std::vector<std::string> &args) const;
        int printSignalMask(const std::vector<std::string> &args) const;
};

#endif