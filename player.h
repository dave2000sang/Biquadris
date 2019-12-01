#ifndef PLAYER_H
#define PLAYER_H

#include "abstract_player.h"
using namespace std;

class Player : public AbstractPlayer{

  public:
    Player(string fileName);
    void attachObserver(Observer<Info>* gs) override;

    // For Testing
    friend std::ostream &operator<<(std::ostream &out, const Player &p);
};

#endif
