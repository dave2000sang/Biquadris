#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "block_factory/block_factory.h"
#include "blocks/block.h"
#include "block_info.h"
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Player {
    
    
    // Helper functions
    int getScore(int linesCleared);
    void updateFactory();

  public:
    //***************************public for testing
    unique_ptr<Board> board;
    unique_ptr<BlockFactory> blockFactory;
    string levelZeroFile;
    Block nextBlock;
    Block nextNextBlock;
    vector<BlockInfo> activeBlocks;
    int score, level, blockID, starCounter;
    //***************************public for testing


    Player(string fileName);
    bool blockIsValid();
    void rotate(string dir);
    void translate(int x, int y);
    void levelUp();
    void levelDown();
    void noRandom(string file);
    void setRandom();
    void replaceBlock(char c);
    void drop();

    // Getter Methods
    int getScore();
    int getLevel();
    Block getNextNextBlock();

    // For Testing
    friend std::ostream &operator<<(std::ostream &out, const Player &p);
};

#endif
