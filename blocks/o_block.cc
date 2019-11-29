#include "o_block.h"
#include <iostream>
using namespace std;

OBlock::OBlock(int level) : Block(2, 2, level, 'O') {
    cells[0][0] = true;
    cells[0][1] = true;
    cells[1][0] = true;
    cells[1][1] = true;
}

OBlock::~OBlock() {}
