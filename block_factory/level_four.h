#ifndef LEVEL_FOUR_H
#define LEVEL_FOUR_H

#include "block_factory.h"
#include <fstream>
using namespace std;

class LevelFour : public BlockFactory {
  ifstream in;
  bool random = true;
  public:
    Block createBlock() override;
    void setRandom() override;
    void setFile(string fileName) override;
};

#endif

