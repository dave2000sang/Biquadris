#ifndef HEAVY_BOARD_H
#define HEAVY_BOARD_H

#include "penalty_decorator.h"

class HeavyBoard : PenaltyDecorator {
  public:
    HeavyBoard(WrapperBoard *board);
    void drop(Block block);
    void translate(char dir);
};
#endif
