#include "command.h"
#include "command_type.h"
#include <string>
#include <vector>
#include <iostream>     // for testing

using namespace std;

Command::Command() {
    commands = {
        {"left", CommandType::left},
        {"right", CommandType::right},
        {"down", CommandType::down},
        {"clockwise", CommandType::clockwise},
        {"counterclockwise", CommandType::counterclockwise},
        {"drop", CommandType::drop},
        {"levelup", CommandType::levelup},
        {"leveldown", CommandType::leveldown},
        {"norandom", CommandType::norandom},
        {"random", CommandType::random},
        {"I", CommandType::I},
        {"J", CommandType::J},
        {"L", CommandType::L},
        {"O", CommandType::O},
        {"S", CommandType::S},
        {"Z", CommandType::Z},
        {"T", CommandType::T},
        {"sequence", CommandType::sequence},
        {"restart", CommandType::restart}
    };
}

// also remove multiplier from cmd if present
int Command::parseMultiplier(string &cmd) {
    int ind = 0;
    for (int i = 0; i < cmd.length(); i++) {
        if (cmd[i] < '0' || cmd[i] > '9') {
            ind = i;
            break;
        }
    }
    if (ind) {
        int ans = stoi(cmd.substr(0, ind));
        // remove multiplier from cmd
        cmd = cmd.substr(ind);
        return ans;
    }
    return 1;
}

CommandType Command::parseCommand(string cmd) {
    auto match = commands.find(cmd);
    if (match != commands.end()) {
        return match->second;
    }

    // find the partial match
    vector<CommandType> matches;
    for (auto const &itr : commands) {
        string cur = itr.first;
        for (int i = 0; i < cur.length(); i++) {
            if (cmd == cur.substr(0, i)) {
                matches.push_back(itr.second);
            }
        }
    }
    if (matches.size() == 1) {
        return matches[0];
    }
    // no match
    return CommandType::nomatch;
}
