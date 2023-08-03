#include "../headers/ApplicationRunner.h"
#include "../headers/UtilityFunctions.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <exception>

#include <pthread.h>

void Application_Runner::run() const
{
    while(true)
    {
        std::string curret_directory = current_working_directory();
        std::cout << curret_directory <<"$ ";

        std::string user_input;
        getline(std::cin, user_input);

        if(user_input=="q") break;

        pthread_t log_thread;
        pthread_create(&log_thread, nullptr, CommandLogger::logToFile, &user_input);
        pthread_detach(log_thread);

        std::pair<std::string, std::vector<std::string>> pair;
        pair = command_parser.parseCommand(user_input);
        
        std::shared_ptr<ICommand> command_to_execute;
        
        try{
            command_to_execute = command_picker.pick_command(pair.first);
        }
        catch(std::exception &e)
        {
            std::cout << "No such command: " << pair.first << std::endl;
            continue;
        }

        int command_result = command_to_execute->executeCommand(pair.second);

        if(command_result)
        {
            const std::string error = error_manager.retrieveError();
            std::cout << error << std::endl;
        }

        else std::cout << std::endl;
    }
}