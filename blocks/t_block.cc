#include "t_block.h"
#include <iostream>
using namespace std;

TBlock::TBlock(int level) : Block(3, 2, level, 'T') {
    cells[0][0] = true;
    cells[0][1] = true;
    cells[0][2] = true;
    cells[1][1] = true;
}

TBlock::~TBlock() {}
