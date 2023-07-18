#include "../../headers/CommandHeaders/Time.h"

#include <time.h> // for time related functions
#include <iostream>

int Time::executeCommand(const std::vector<std::string>&) const
{
    time_t time_since_epoch = time(nullptr);

    // Check if time failed
    if(time_since_epoch == -1) return -1;

    char *timep = ctime(&time_since_epoch);

    if(timep==nullptr) return -1;

    std::string readable_time{timep};

    std::cout << readable_time;

    return 0;
}