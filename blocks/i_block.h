#ifndef I_BLOCK_H
#define I_BLOCK_H

#include <vector>
#include <string>
#include "block.h"

class IBlock : public Block {
  public:
    IBlock(int x, int y, int level);
    ~IBlock();
};
#endif
