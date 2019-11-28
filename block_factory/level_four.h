#ifndef LEVEL_FOUR_H
#define LEVEL_FOUR_H

#include "block.h"
#include <iostream>
using namespace std;

class LevelFour : public BlockFactory {
  ifstream in;
  bool random;
  public:
    Block createBlock() override;
    void setRandom() override;
    void setFile(string fileName) override;
};

#endif