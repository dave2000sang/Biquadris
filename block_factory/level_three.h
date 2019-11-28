#ifndef LEVEL_THREE_H
#define LEVEL_THREE_H

#include "block.h"
using namespace std;

class LevelThree : BlockFactory {
  public:
    Block* createBlock() override;
};

#endif