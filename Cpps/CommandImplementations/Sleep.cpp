#include "../../headers/CommandHeaders/Sleep.h"
#include <unistd.h> // sleep()
#include <time.h> // for nanosleep()

int Sleep::executeCommand(const std::vector<std::string> &args) const
{
    if(args[0]=="-nano")
    {
        struct timespec request;
        struct timespec remain;

        request.tv_sec = std::stoi(args[1]);
        request.tv_nsec = 0;

        for(;;)
        {
            if(nanosleep(&request, &remain) == -1)
            {
                if(errno==EINTR)
                {
                    // Sleep was interrupted, changes request to remain
                    request = remain;
                }
                else
                {
                    return -1;
                }
            }
            else return 0;
        }
    }
    else
    {
        unsigned seconds = std::stoi(args[0]);
        for(;;)
        {
            seconds = sleep(seconds);
            if(seconds && errno == EINTR) continue;
            return 0;
        }
    }
}