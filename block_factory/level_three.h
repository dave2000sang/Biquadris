#ifndef LEVEL_THREE_H
#define LEVEL_THREE_H

#include "block.h"
#include <iostream>
using namespace std;

class LevelThree : public BlockFactory {
  ifstream in;
  bool random;
  public:
    Block createBlock() override;
    void setRandom() override;
    void setFile(string fileName) override;
};

#endif