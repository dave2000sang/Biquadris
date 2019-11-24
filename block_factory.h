#ifndef BLOCK_FACTORY_H
#define BLOCK_FACTORY_H

#include "block.h"

class BlockFactory {
    std::string file;
  public:
    Block createBlock();
};

#endif

