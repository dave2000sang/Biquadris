#ifndef BOARD_H
#define BOARD_H
#include "cell.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "blocks/block.h"
#include "block_info.h"


// TODO: attach textdisplay and graphics pointers
class Board {
    std::vector<std::vector<Cell>> theBoard;
    int width, height;
    std::vector<BlockInfo> activeBlocks;

    public:

    int drop(Block &block, char type, int ID);
    int clearLines(); // returns # of lines cleared
    std::vector<int> getIDs(); // unique IDs without 0
    void init(int width, int height);
    void reverse();

    // helpers
    bool isRowFull(std::vector<Cell> &row);
    bool canTranslateDown(Block &block, int x, int y);

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
