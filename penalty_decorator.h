#ifndef PENALTY_DECORATOR_H
#define PENALTY_DECORATOR_H

#include "wrapper_board.h"

class PenaltyDecorator : WrapperBoard {
    WrapperBoard *wrapperBoard;
    vector<vector<Cell>> board;
    vector<BlockInfo>;
    int width, height;
  public:
    PenaltyDecorator(WrapperBoard *wrapperBoard);
    virtual ~PenaltyDecorator();
    void drop(Block block);
    void translate(int x, int y);
};

#endif
