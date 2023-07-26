#include "../../headers/CommandHeaders/Run.h"

#include <unistd.h> // for fork()
#include <sys/wait.h> // for waitpid()

int Run::executeCommand(const std::vector<std::string> &args) const
{
    pid_t childPid;
    char *exec_args[] = {nullptr};
    switch (childPid = fork())
    {
        case -1:
            return -1;
        case 0:
            execv(args[0].c_str(), exec_args);
            // If we get here means an error has happened
            return -1;
        default:
            int status;
            if(waitpid(childPid, &status, 0)==-1)
            {
                return -1;
            }
            return 0;
    }
    return 0;
}