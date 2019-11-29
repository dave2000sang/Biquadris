#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "block_factory.h"
#include "blocks/block.h"
#include "block_info.h"
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Player {
    unique_ptr<Board> board;
    unique_ptr<BlockFactory> blockFactory;
    Block nextBlock;
    vector<BlockInfo> activeBlocks;
    string levelZeroFile;
    int score, level, blockID, starCounter;
    
    // Helper functions
    int getScore(int linesCleared);
    void updateFactory();

  public:
    Player(string fileName);
    void blockIsValid();
    void rotate(string dir);
    void translate(int x, int y);
    void levelUp();
    void levelDown();
    void noRandom(string file);
    void setRandom();
    void replaceBlock(char Block);
    void drop();
};

#endif
