#include "z_block.h"
#include <iostream>
using namespace std;

ZBlock::ZBlock(int level) : Block(3, 2, level, 'Z') {
    cells[0][0] = true;
    cells[0][1] = true;
    cells[1][1] = true;
    cells[1][2] = true;
}

ZBlock::~ZBlock() {}
