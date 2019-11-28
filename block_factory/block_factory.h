#ifndef BLOCK_FACTORY_H
#define BLOCK_FACTORY_H

#include "block.h"

class BlockFactory {
    std::string file;
  public:
    void setFile(string fileName);
    virtual Block* createBlock() = 0;
    virtual void noRandom();
};

#endif

