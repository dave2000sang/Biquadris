#ifndef T_BLOCK_H
#define T_BLOCK_H

#include <vector>
#include <string>
#include "block.h"

class TBlock : public Block {
  public:
    TBlock(int level);
    ~TBlock();
};
#endif
