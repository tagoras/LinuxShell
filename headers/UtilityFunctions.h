#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <string>
#include <pwd.h>

const std::string current_working_directory();
uid_t username_to_id(const std::string &username);

#endif