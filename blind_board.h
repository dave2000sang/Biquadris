#ifndef BLIND_BOARD_H
#define BLIND_BOARD_H

#include "penalty_decorator.h"

class BlindBoard : PenaltyDecorator {
  public:
    BlindBoard(WrapperBoard *board);
    void drop(Block block);
    void translate(char dir);
};
#endif
