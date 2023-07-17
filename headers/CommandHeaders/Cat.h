#ifndef CAT_H
#define CAT_H

#include "../ICommand.h"

class Cat : public ICommand{
    public:
        virtual int executeCommand(const std::vector<std::string> &args) const override;
};

#endif