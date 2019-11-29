#ifndef I_BLOCK_H
#define I_BLOCK_H

#include <vector>
#include <string>
#include "block.h"

class IBlock : public Block {
  public:
    IBlock(int level);
    ~IBlock();
};
#endif
