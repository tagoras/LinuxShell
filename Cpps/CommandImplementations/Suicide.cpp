#include "../../headers/CommandHeaders/Suicide.h"

#include <sys/time.h>
#include <iostream>

int Suicide::executeCommand(const std::vector<std::string> &args) const
{
    if(args[0]=="-SET") return setTimer(args);
    else if(args[0]=="-GET") return getTimer(args);
    else return -1;
}

int Suicide::setTimer(const std::vector<std::string> &args) const
{
    struct itimerval new_value;
    struct timeval value;
    struct timeval interval;
    
    value.tv_sec = std::stoi(args[1]);
    value.tv_usec = 0;
    
    interval.tv_sec = std::stoi(args[2]);
    interval.tv_usec = 0;

    new_value.it_interval = interval;
    new_value.it_value = value;

    return setitimer(ITIMER_REAL, &new_value, nullptr);
}

int Suicide::getTimer(const std::vector<std::string> &args) const
{
    struct itimerval timer_info;
    if(getitimer(ITIMER_REAL, &timer_info) == -1)
    {
        return -1;
    }
    struct tm *structured_time;
    structured_time = gmtime(&timer_info.it_value.tv_sec);

    int time_in_seconds = structured_time->tm_sec;
    std::cout << time_in_seconds;
    return 0;
}