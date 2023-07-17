#include "../../headers/CommandHeaders/Ln.h"

#include <unistd.h> // for link(), symlink()

int Ln::executeCommand(const std::vector<std::string> &args) const {
    if(args.size()==3 && args[0]=="-s") return symbolicLink(args);
    else if(args.size()==2) return hardLink(args);
    else return -1;
}

int Ln::symbolicLink(const std::vector<std::string> &args) const {
    return symlink(args[1].c_str(), args[2].c_str());
}

int Ln::hardLink(const std::vector<std::string> &args) const {
    return link(args[0].c_str(), args[1].c_str());
}