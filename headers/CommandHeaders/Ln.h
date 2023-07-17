#ifndef LN_H
#define LN_H

#include "../ICommand.h"
#include <vector>
#include <string>

class Ln : public ICommand{
    public:
        int executeCommand(const std::vector<std::string>&) const override;
        int symbolicLink(const std::vector<std::string>&) const;
        int hardLink(const std::vector<std::string>&) const;
};

#endif