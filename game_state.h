#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
#include "abstract_player.h"
#include "player.h"
#include "blocks/block.h"
#include "displays/info.h"
#include "displays/observer.h"
#include "displays/text_display.h"
#include <memory>

class GameState : public Observer<Info> {
    std::shared_ptr<AbstractPlayer> p1, p2;
    int turn;
    
  public:

    std::shared_ptr<TextDisplay> td;
    
    GameState();
    void notify(Subject<Info> &whoFrom) override;
    void rotate(int reps, std::string dir);
    void translate(int reps, int x, int y);
    void drop(int multiplier);
    void levelUp(int multiplier);
    void levelDown(int multiplier);
    void noRandom(std::string file);
    void setRandom();
    void replaceBlock(char block);
    int getScore(int player);
    void attachToSubjects();
    void makeEffect(int targetPlayer);
};

#endif
