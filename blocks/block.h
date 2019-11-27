#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>

class Block {
  protected:    // Should be private ?
    int x, y;
    int w, h;   // width and height of bounding rectangle
    int level;
    char type;
    std::vector<std::vector<bool>> cells;
  public:
    Block(int x, int y, int w, int h, int level, char type);
    virtual ~Block();
    bool rotate(std::string dir);
    bool translate(int x, int y);

    // getters
    int getX();
    int getY();


    friend std::ostream &operator<<(std::ostream &out, const Block& b);
};
#endif
