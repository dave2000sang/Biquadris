#ifndef LEVEL_ZERO_H
#define LEVEL_ZERO_H

include "block.h"
#include <iostream>
using namespace std;

class LevelZero : BlockFactory {
    ifstream in;

  public:
    LevelZero(string fileName);
    Block* createBlock() override;
};

#endif
