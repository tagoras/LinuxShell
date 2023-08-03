#ifndef FIND_H
#define FIND_H

#include "../ICommand.h"

#include <vector>
#include <string>
#include <dirent.h>

class Find : public ICommand{
    public:
        int executeCommand(const std::vector<std::string> &args) const override;
    private:
        static void *thread_function(void *data);
};

#endif