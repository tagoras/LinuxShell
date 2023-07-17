#include "../../headers/CommandHeaders/Id.h"

#include <unistd.h> // for getuid(), geteuid(), getgid(), geteguid() + system structures
#include <iostream>

int Id::executeCommand(const std::vector<std::string> &args) const {
    uid_t real_user_id;
    uid_t effective_uid;
    gid_t real_group_id;
    gid_t effective_group_id;

    real_user_id = getuid();
    effective_uid = geteuid();
    real_group_id = getgid();
    effective_group_id = getegid();

    std::cout << "uid="<<real_user_id << " euid=" << effective_uid << " gid=" << real_group_id << " egid=" << effective_group_id;

    return 0;
}