#ifndef CP_H
#define CP_H

#include "ICommand.h"

class Cp : public ICommand{
    public:
        int executeCommand(const std::vector<std::string>&)const override;
};


#endif