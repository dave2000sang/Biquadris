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
    shared_ptr<Board> board;
    shared_ptr<BlockFactory> blockFactory;
    string levelZeroFile;
    Block nextBlock;
    Block nextNextBlock;
    vector<BlockInfo> activeBlocks;
    int score, level, blockID, starCounter;

     // Helper functions
    int calculateScore(int linesCleared);
    void updateFactory();

public:
    bool blockIsValid();
    void rotate(string dir);
    bool translate(int x, int y);
    void levelUp();
    void levelDown();
    void noRandom(string file);
    void setRandom();
    void replaceBlock(char c);
    virtual void drop();
    virtual bool lowerIfHeavy();
    virtual void attachObserver(Observer<Info>* gs) = 0;

    // Getter Methods
    int getScore();
    int getLevel();
    Block getNextNextBlock();
};




#endif