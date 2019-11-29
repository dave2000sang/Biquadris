#ifndef O_BLOCK_H
#define O_BLOCK_H

#include <vector>
#include <string>
#include "block.h"

class OBlock : public Block {
  public:
    OBlock(int level);
    ~OBlock();
};
#endif
