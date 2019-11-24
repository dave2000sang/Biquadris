#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
#include "player.h"

class GameState {
    Player p1, p2;
    int turn;
    // GameDisplay *gd;
  public:
    void rotate(int reps, char dir);
    void translate(int reps, char dir);
    void changeLevel(int change);
    void noRandom(std::string file);
    void setRandom();
    void setSequence(std::string file);
    void replaceBlock();
    void restart();
};

#endif
