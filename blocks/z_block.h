#ifndef Z_BLOCK_H
#define Z_BLOCK_H

#include <vector>
#include <string>
#include "block.h"

class ZBlock : public Block {
  public:
    ZBlock(int level);
    ~ZBlock();
};
#endif
