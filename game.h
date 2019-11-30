#ifndef GAME_H
#define GAME_H

#include "game_state.h"
#include "command.h"

class Game {
    unique_ptr<GameState> game;
    Command cmdInterp;
    int highScore;
  public:
    Game();
    void play();
    void restart(int whoWon);
};

#endif
