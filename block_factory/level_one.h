#ifndef LEVEL_ONE_H
#define LEVEL_ONE_H

#include "block.h"
using namespace std;

class LevelOne : BlockFactory {
  public:
    Block* createBlock() override;
};

#endif