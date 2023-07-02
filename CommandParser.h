#ifndef COMMAND_PARSER
#define COMMAND_PARSER

#include <map>
#include <string>
#include <vector>

// This class is used to retrieve the command name from the shell
class CommandParser{
    public:
        std::pair<std::string, std::vector<std::string>> parseCommand(const std::string &input_line) const;
};

#endif