#ifndef L_BLOCK_H
#define L_BLOCK_H

#include <vector>
#include <string>
#include "block.h"

class LBlock : public Block {
  public:
    LBlock(int level);
    ~LBlock();
};
#endif
