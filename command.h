#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>
#include "command_type.h"

class Command {
    std::map<std::string, CommandType> commands;
  public:
    Command();
    int parseMultiplier(std::string &cmd);
    CommandType parseCommand(std::string cmd);
};

#endif
