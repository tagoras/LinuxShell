#include "../headers/ApplicationRunner.h"
#include "../headers/UtilityFunctions.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>

void Application_Runner::run() const
{

    while(true)
    {
        std::string curret_directory = current_working_directory();
        std::cout << curret_directory <<"$ ";

        std::string user_input;
        getline(std::cin, user_input);

        std::pair<std::string, std::vector<std::string>> pair;
        pair = command_parser.parseCommand(user_input);
        
        std::shared_ptr<ICommand> command_to_execute = command_picker.pick_command(pair.first);
        int command_result = command_to_execute->executeCommand(pair.second);

        if(command_result)
        {
            const std::string error = error_manager.retrieveError();
            std::cout << error << std::endl;
        }

        else std::cout << std::endl;
    }
}