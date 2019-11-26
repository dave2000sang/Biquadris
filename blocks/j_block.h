#ifndef J_BLOCK_H
#define J_BLOCK_H

#include <vector>
#include <string>
#include "block.h"

class JBlock : public Block {
  public:
    JBlock(int x, int y, int level);
    ~JBlock();
};
#endif
