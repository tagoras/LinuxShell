#include "../headers/UtilityFunctions.h"

#include <unistd.h>
#include <linux/limits.h>

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