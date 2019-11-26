#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "wrapper_board.h"
#include "cell.h"

class BlockInfo;
class BasicBoard : WrapperBoard {
    std::vector<std::vector<Cell>> board;
    std::vector<BlockInfo>;
    int width, height;
  public:
    void drop(Block block);
    void translate(int x, int y);
};

#endif
