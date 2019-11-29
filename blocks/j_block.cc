#include "j_block.h"
#include <iostream>
using namespace std;

JBlock::JBlock(int level) : Block(3, 2, level, 'J') {
    cells[0][0] = true;
    cells[1][0] = true;
    cells[1][1] = true;
    cells[1][2] = true;
}

JBlock::~JBlock() {}
