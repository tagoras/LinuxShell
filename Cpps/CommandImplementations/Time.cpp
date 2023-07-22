#include "../../headers/CommandHeaders/Time.h"

#include <time.h> // for time related functions: time(), clock_gettime(), clock_getres()
#include <iostream>

int Time::executeCommand(const std::vector<std::string>&args) const
{
    if(args.size()==0) return timeEpoch();
    else if(args[0]=="-S" || args[0] == "-SYSTEM") return timeSystem();
    else return -1;
}

int Time::timeEpoch() const
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

int Time::timeSystem() const
{
    struct timespec time;
    if(clock_gettime(CLOCK_MONOTONIC, &time)==-1)
    {
        return -1;
    }
    std::cout << time.tv_sec << std::endl;
    // Print out system run time
    int hours, minutes, seconds;
    
    if(time.tv_sec>=3600)
    {
        hours = time.tv_sec/3600;
        time.tv_sec%=3600;
    }
    if(time.tv_sec>=60)
    {
        minutes = time.tv_sec/60;
        time.tv_sec%=3600;
    }
    std::cout << hours << ":" << minutes << ":" << seconds;
    return 0;
}