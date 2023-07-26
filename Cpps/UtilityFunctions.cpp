#include "../headers/UtilityFunctions.h"

#include <unistd.h>
#include <linux/limits.h>

#include <iostream>
#include <map>

#include <signal.h>
#include <exception>

const std::string current_working_directory()
{
    char buf[PATH_MAX];
    getcwd(buf, PATH_MAX);

    if(buf==NULL)
    {
        /*Handle error where current working directory could not be retrieved*/
    }
    else
    {
        std::string cwd{buf};
        return cwd;
    }
}

uid_t username_to_id(const std::string &username)
{
    struct passwd *password_record;
    password_record=getpwnam(username.c_str());
    return password_record->pw_uid;
}

gid_t groupname_to_id(const std::string &groupname)
{
    struct group *group_record;
    group_record = getgrnam(groupname.c_str());
    return group_record->gr_gid;
}

void sureKillHandler(int)
{
    std::cout << "The process received sure kill signal, exiting" << std::endl;
    exit(EXIT_FAILURE);
}

int stringToSignal(const std::string &signal_constant)
{
    static const std::map<const std::string, int> string_signal_map = {
        {"SIGHUP", SIGHUP},
        {"SIGINT", SIGINT},
        {"SIGQUIT", SIGQUIT},
        {"SIGILL", SIGILL},
        {"SIGABRT", SIGABRT},
        {"SIGFPE", SIGFPE},
        {"SIGKILL", SIGKILL},
        {"SIGSEGV", SIGSEGV},
        {"SIGPIPE", SIGPIPE},
        {"SIGALRM", SIGALRM},
        {"SIGTERM", SIGTERM},
        {"SIGUSR1", SIGUSR1},
        {"SIGUSR2", SIGUSR2},
        {"SIGCHLD", SIGCHLD},
        {"SIGCONT", SIGCONT},
        {"SIGSTOP", SIGSTOP},
        {"SIGTSTP", SIGTSTP},
        {"SIGTTIN", SIGTTIN},
        {"SIGTTOU", SIGTTOU},
        {"SIGBUS", SIGBUS},
        {"SIGPROF", SIGPROF},
        {"SIGSYS", SIGSYS},
        {"SIGTRAP", SIGTRAP},
        {"SIGURG", SIGURG},
        {"SIGVTALRM", SIGVTALRM},
        {"SIGXCPU", SIGXCPU},
        {"SIGXFSZ", SIGXFSZ},
        // Add more signals here if needed
    };

    auto it = string_signal_map.find(signal_constant);
    if(it != string_signal_map.end())
    {
        return it->second;
    }
    else return -1;
}