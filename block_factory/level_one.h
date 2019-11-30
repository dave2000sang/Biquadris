#ifndef LEVEL_ONE_H
#define LEVEL_ONE_H

#include "block_factory.h"
using namespace std;

class LevelOne : public BlockFactory {
  public:
    Block createBlock() override;
};

#endif