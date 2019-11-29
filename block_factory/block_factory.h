#ifndef BLOCK_FACTORY_H
#define BLOCK_FACTORY_H

#include "../blocks/block.h"
#include "../blocks/i_block.h"
#include "../blocks/j_block.h"
#include "../blocks/l_block.h"
#include "../blocks/t_block.h"
#include "../blocks/s_block.h"
#include "../blocks/z_block.h"
#include "../blocks/o_block.h"
#include <string>

class BlockFactory {
  protected:
    std::string file;
  public:
    virtual Block createBlock() = 0;
    virtual void setFile(std::string fileName);
    virtual void setRandom();
};

#endif

