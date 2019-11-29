#include "s_block.h"
#include <iostream>
using namespace std;

SBlock::SBlock(int level) : Block(3, 2, level, 'S') {
    cells[0][1] = true;
    cells[0][2] = true;
    cells[1][0] = true;
    cells[1][1] = true;
}

SBlock::~SBlock() {}
