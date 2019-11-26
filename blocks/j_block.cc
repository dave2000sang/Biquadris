#include "j_block.h"
#include <iostream>
using namespace std;

JBlock::JBlock(int x, int y, int level) : Block(x, y, 3, 2, level) {
    cells[0][0] = true;
    cells[1][0] = true;
    cells[1][1] = true;
    cells[1][2] = true;
}

JBlock::~JBlock() {}
