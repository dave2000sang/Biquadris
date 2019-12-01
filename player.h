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

    bool blockIsValid() override;
    void rotate(string dir) override;
    bool translate(int x, int y) override;
    void levelUp() override;
    void levelDown() override;
    void noRandom(string file) override;
    void setRandom() override;
    void replaceBlock(char c) override;
    void toggleBlind(bool blind) override;
    int drop() override;
    bool lowerIfHeavy(bool ifLeftRight) override;
    int calculateScore(int linesCleared) override;
    void updateFactory() override;

    // Getter Methods
    int getScore() override;
    int getLevel() override;
    Block getNextNextBlock() override;

    // For Testing
    friend std::ostream &operator<<(std::ostream &out, const Player &p);
};

#endif
