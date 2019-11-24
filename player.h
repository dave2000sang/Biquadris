#ifndef PLAYER_H
#define PLAYER_H

#include "wrapper_board.h"
#include "block_factory.h"

class Player {
    WrapperBoard *board;
    int score;
    int level;
    BlockFactory *blockFactory;
  public:
};

#endif
