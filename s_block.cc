#include "s_block.h"
#include <iostream>
using namespace std;

SBlock::SBlock(int x, int y, int level) : Block(x, y, 3, 2, level) {
    cells[0][1] = true;
    cells[0][2] = true;
    cells[1][0] = true;
    cells[1][1] = true;
}

SBlock::~SBlock() {}
