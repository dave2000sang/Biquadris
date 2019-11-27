#ifndef BOARD_H
#define BOARD_H
#include "cell.h"
#include <iostream>
#include <vector>
#include "blocks/block.h"
#include "block_info.h"


// TODO: attach textdisplay and graphics pointers
class Board {
    std::vector<std::vector<Cell>> theBoard;
    int width, height;
    std::vector<BlockInfo> activeBlocks;

    public:
    void init(int width, int height);
    bool canTranslateDown(Block &block, int x, int y);
    void drop(Block &block, char type, int ID);
    int clearLines();
    void reverse();

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
