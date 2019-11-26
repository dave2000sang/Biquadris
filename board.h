#ifndef BOARD_H
#define BOARD_H
#include "cell.h"
#include <iostream>
#include <vector>

class Block;
class BlockInfo;

// TODO: attach textdisplay and graphics pointers
class Board {
    std::vector<std::vector<Cell>> theBoard;
    int width, height;
    vector<BlockInfo> activeBlocks;

    public:
    void drop(Block &block);
    int clearLines();
    void reverse();

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
