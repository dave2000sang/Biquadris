#ifndef GAME_H
#define GAME_H

#include "game_state.h"
#include "command.h"

class Game {
    int startlevel;
    std::string file1, file2;
    shared_ptr<GameState> game;
    Command cmdInterp;
    int highScore;
  public:
    Game(int startlevel, std::string file1, std::string file2);
    void play();
    void restart();
};

#endif
