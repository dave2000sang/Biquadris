#ifndef LEVEL_FOUR_H
#define LEVEL_FOUR_H

#include "block.h"
using namespace std;

class LevelFour : BlockFactory {
  public:
    Block* createBlock() override;
};

#endif