#ifndef S_BLOCK_H
#define S_BLOCK_H

#include <vector>
#include <string>
#include "block.h"

class SBlock : public Block {
  public:
    SBlock(int x, int y, int level);
    ~SBlock();
};
#endif
