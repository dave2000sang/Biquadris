#include "board.h"
using namespace std;

void Board::init(int width, int height) {
    theBoard.clear();
    activeBlocks.clear();
    this->width = width;
    this->height = height;

    theBoard = vector<vector<Cell>> (height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            theBoard[i].emplace_back(Cell{i, j, 0, '-'}); // TODO: change to ' '
        }
    }
}

bool Board::canTranslateDown(Block &block, int x, int y) {
    if ((y + block.h) >= (height)) {
        return false;
    }
    for (int i = 0; i < block.h; ++i) {
        for (int j = 0; j < block.w; ++j) {
            if (block.cells[i][j] && (theBoard[i + y + 1][j + x].type != '-')) {  // TODO: change to ' '
                return false;
            }
        }
    }
    return true;
}

void Board::drop(Block &block, char type, int ID) { // TODO: get type from block
    int x = block.x;
    int y = block.y - block.h + 1;
    int w = block.w;
    int h = block.h;

    // find position
    while (y + block.h < this->height) {
        if (!canTranslateDown(block, x, y)) {
            break;
        }
        y++;
    }
    
    // update board
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (block.cells[i][j]) {
                theBoard[i + y][j + x].type = type;
                theBoard[i + y][j + x].id = ID;
            }
        }
    }
}

int Board::clearLines() {
    // TODO
}

ostream &operator<<(std::ostream &out, const Board &b) {
    for (auto row : b.theBoard) {
        for (auto cell : row) {
            out << cell.type;
        }
        out << endl;
    }
    return out;
}
