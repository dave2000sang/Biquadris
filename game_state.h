#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
#include "player.h"
#include "blocks/block.h"
#include "displays/info.h"
#include "displays/observer.h"
#include "displays/text_display.h"
#include <memory>

class GameState : public Observer<Info> {
    std::unique_ptr<Player> p1, p2;
    int turn;
    std::unique_ptr<TextDisplay> td;
  public:
    GameState();
    void notify(Subject<Info> &whoFrom) override;
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
