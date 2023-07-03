#include "../headers/ApplicationRunner.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>

void Application_Runner::run() const
{
    while(true)
    {
        std::cout << "> ";

        std::string user_input;
        getline(std::cin, user_input);

        std::pair<std::string, std::vector<std::string>> pair;
        pair = command_parser.parseCommand(user_input);

        std::cout << "Executing command: " << pair.first << std::endl;
        std::cout << "Arguments are:";

        for(std::string arg : pair.second)
        {
            std::cout << arg << " ";
        }
        std::cout << std::endl;
    }
}