#include "i_block.h"
#include <iostream>
using namespace std;

IBlock::IBlock(int x, int y, int level) : Block(x, y, 4, 1, level, 'I') {
    cells[0][0] = true;
    cells[0][1] = true;
    cells[0][2] = true;
    cells[0][3] = true;
}

IBlock::~IBlock() {}
