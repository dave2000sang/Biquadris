#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>

class Board;
class Block {
  protected:    // Should be private ?
    int x, y;
    int w, h;   // width and height of bounding rectangle
    int level;
    char type;
    std::vector<std::vector<bool>> cells;
  public:
    Block(int w, int h, int level, char type, int x=0, int y=3);
    Block();
    virtual ~Block();
    bool rotate(std::string dir);
    bool translate(int x, int y);

    // getters
    int getX();
    int getY();
    int getW();
    int getH();
    char getType();
    std::vector<std::vector<bool>> getCells();

    // should we use friend class ?
    friend class Board;
    friend std::ostream &operator<<(std::ostream &out, const Block& b);
};
#endif
