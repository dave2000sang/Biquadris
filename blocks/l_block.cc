#include "l_block.h"
#include <iostream>
using namespace std;

LBlock::LBlock(int x, int y, int level) : Block(x, y, 3, 2, level, 'L') {
    cells[0][2] = true;
    cells[1][0] = true;
    cells[1][1] = true;
    cells[1][2] = true;
}

LBlock::~LBlock() {}
