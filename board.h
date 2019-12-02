#ifndef BOARD_H
#define BOARD_H
#include "cell.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "blocks/block.h"
#include "block_info.h"

class GameState;
// TODO: attach textdisplay and graphics pointers
class Board {
    std::vector<std::vector<Cell>> theBoard;
    int width, height;

    public:

    int drop(Block &block, int ID);
    int clearLines(); // returns # of lines cleared
    std::vector<int> getIDs(); // unique IDs without 0
    void init(int width = 11, int height = 18);
    std::vector<std::vector<Cell>> getBoard();
    void dropStar();
    void erase(const Block b);
    void draw(const Block b, int ID);
    void attachObserver(Observer<Info>* gs);
    void updateLevel();
    void toggleBlind(bool blind);

    // helpers
    bool isRowFull(std::vector<Cell> &row);
    bool canTranslateDown(Block &block, int x, int y);

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
