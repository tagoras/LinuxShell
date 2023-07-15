#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <string>
#include <pwd.h>
#include <grp.h>

const std::string current_working_directory();
uid_t username_to_id(const std::string &username);
gid_t groupname_to_id(const std::string &groupname);

#endif