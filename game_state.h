#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
#include "player.h"
#include "blocks/block.h"
#include <memory>

class GameState {
    std::unique_ptr<Player> p1, p2;
    int turn;
    // GameDisplay *gd;
  public:
    GameState();
    void rotate(int reps, std::string dir);
    void translate(int reps, int x, int y);
    void drop();
    void levelUp(int multiplier);
    void levelDown(int multiplier);
    void noRandom(std::string file);
    void setRandom();
    void replaceBlock(char block);
    void restart();
    void updateTurn();
};

#endif
