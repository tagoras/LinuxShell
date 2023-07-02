#include "CommandParser.h"

#include <iostream>
#include <regex>

std::pair<std::string, std::vector<std::string>> CommandParser::parseCommand(const std::string &input_line) const
{
    std::regex pattern{"\\S+"};

    std::sregex_iterator begin = std::sregex_iterator(input_line.begin(), input_line.end(), pattern);
    std::sregex_iterator end = std::sregex_iterator();

    std::vector<std::string> args;
    std::string command_name = begin->str();

    ++begin;

    for(std::sregex_iterator i = begin;i!=end;++i)
    {
        args.push_back(i->str());
    }
    return {command_name, args};
}