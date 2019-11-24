#ifndef FORCE_BOARD_H
#define FORCE_BOARD_H

#include "penalty_decorator.h"

class ForceBoard : PenaltyDecorator {
  public:
    ForceBoard(WrapperBoard *board);
    void drop(Block block);
    void translate(char dir);
};
#endif
