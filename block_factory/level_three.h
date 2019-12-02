#ifndef LEVEL_THREE_H
#define LEVEL_THREE_H

#include "block_factory.h"
#include <fstream>
using namespace std;

class LevelThree : public BlockFactory {
  ifstream in;
  bool random = true;
  public:
    Block createBlock() override;
    void setRandom() override;
    void setFile(string fileName) override;
};

#endif

