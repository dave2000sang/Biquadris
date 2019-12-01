#ifndef PLAYER_H
#define PLAYER_H

#include "abstract_player.h"
using namespace std;

class Player : public AbstractPlayer{
    shared_ptr<Board> board;
    shared_ptr<BlockFactory> blockFactory;
    string levelZeroFile;
    Block nextBlock;
    Block nextNextBlock;
    vector<BlockInfo> activeBlocks;
    int score, level, blockID, starCounter;

  public:
    Player(string fileName);
    void attachObserver(Observer<Info>* gs) override;

    // For Testing
    friend std::ostream &operator<<(std::ostream &out, const Player &p);
};

#endif
