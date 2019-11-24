#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

class Block {
    int points;
    int x, y;
    std::vector<Cell> cells;
  public:
    virtual bool canRotate(char dir) = 0;
    virtual bool canTranslate(char dir) = 0;
    virtual void rotate(char dir) = 0;
};

#endif
