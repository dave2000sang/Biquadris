#include "cell.h"
#ifndef WRAPPER_BOARD_H
#define WRAPPER_BOARD_H

#include "block.h"

class AbstractBoard {
  public:
    virtual void drop(Block block) = 0;
    virtual void translate(int x, int y) = 0;
};

#endif
