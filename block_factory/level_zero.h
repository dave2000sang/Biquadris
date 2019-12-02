#ifndef LEVEL_ZERO_H
#define LEVEL_ZERO_H

#include "block_factory.h"
#include <fstream>
using namespace std;

class LevelZero : public BlockFactory {
    string file;
    ifstream in;
  public:
    LevelZero(string fileName);
    Block createBlock() override;
};

#endif


