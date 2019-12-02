#ifndef ABSTRACT_PLAYER_H
#define ABSTRACT_PLAYER_H

#include "board.h"
#include "block_factory/block_factory.h"
#include "blocks/block.h"
#include "block_info.h"
#include <memory>
#include <vector>
#include <string>
using namespace std;

class GameState;

class AbstractPlayer{
protected:
    
     // Helper functions
public:
    virtual bool blockIsValid() = 0;
    virtual void rotate(string dir) = 0;
    virtual bool translate(int x, int y) = 0;
    virtual void levelUp() = 0;
    virtual void levelDown() = 0;
    virtual void noRandom(string file) = 0;
    virtual void setRandom() = 0;
    virtual void replaceBlock(char c) = 0;
    virtual int drop() = 0;
    virtual bool lowerIfHeavy(bool isLeftRight) = 0;
    virtual void toggleBlind(bool blind) = 0;
    virtual int calculateScore(int linesCleared) = 0;
    virtual void updateFactory() = 0;
    virtual void attachObserver(Observer<Info>* gs) = 0;

    // Getter Methods
    virtual int getScore() = 0;
    virtual void setScore(int s) = 0;
    virtual int getLevel() = 0;
    virtual Block getNextNextBlock() = 0;
};




#endif