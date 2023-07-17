#ifndef CHGRP_H
#define CHGRP_H

#include "../ICommand.h"
#include <string>
#include <vector>

class Chgrp : public ICommand{
    int executeCommand(const std::vector<std::string> &args) const override;
};

#endif