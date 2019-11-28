#ifndef LEVEL_TWO_H
#define LEVEL_TWO_H

#include "block.h"
using namespace std;

class LevelTwo : public BlockFactory {
  public:
    Block createBlock() override;
};

#endif