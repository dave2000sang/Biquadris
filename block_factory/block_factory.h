#ifndef BLOCK_FACTORY_H
#define BLOCK_FACTORY_H

#include "block.h"

class BlockFactory {
    std::string file;
  public:
    virtual Block createBlock() = 0;
    virtual void setFile(string fileName);
    virtual void setRandom();
};

#endif

