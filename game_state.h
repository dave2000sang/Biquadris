#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
#include "player.h"
#include "blocks/block.h"
#include "displays/info.h"
#include "displays/observer.h"
#include "displays/text_display.h"
#include "displays/graphics_display.h"
#include <memory>

class GameState : public Observer<Info> {
    std::shared_ptr<Player> p1, p2;
    int turn;
    int startlevel;
    int curhighscore;
  public:
    bool graphicsActive;
    std::unique_ptr<TextDisplay> td;
    std::unique_ptr<GraphicsDisplay> gd;
    
    GameState(int level, std::string file1, std::string file2, bool graphicsActive);
    void notify(Subject<Info> &whoFrom) override;
    void rotate(int reps, std::string dir);
    void translate(int reps, int x, int y);
    void drop(int multiplier);
    void levelUp(int multiplier);
    void levelDown(int multiplier);
    void noRandom(std::string file);
    void setRandom();
    void replaceBlock(char block);
    int getHighScore();
    void attachToSubjects();
};

#endif
