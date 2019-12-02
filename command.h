#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>
#include <vector>
#include "command_type.h"

class Command {
    std::map<std::string, std::vector<CommandType>> commands;
  public:
    Command();
    int parseMultiplier(std::string &cmd);
    std::vector<CommandType> parseCommand(std::string cmd);
    void addMacro(std::string name, std::vector<CommandType> list);
};

#endif


