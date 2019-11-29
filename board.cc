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
            theBoard[i].emplace_back(Cell{i, j, 0, ' '});
        }
    }
}

bool Board::canTranslateDown(Block &block, int x, int y) {
    if ((y + block.h) >= (height)) {
        return false;
    }
    for (int i = 0; i < block.h; ++i) {
        for (int j = 0; j < block.w; ++j) {
            if (block.cells[i][j] && (theBoard[i + y + 1][j + x].type != ' ')) {
                return false;
            }
        }
    }
    return true;
}

int Board::drop(Block &block, char type, int ID) { // TODO: get type from block
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

    // clear full rows and return # of lines cleared
    return this->clearLines();
}

bool Board::isRowFull(vector<Cell> &row) {
    for (auto cell : row) {
        if (cell.type == ' ') return false;
    }
    return true;
}

int Board::clearLines() {
    int rowsCleared = 0;

    for (int i = 0; i < height; ++i) {
        if (isRowFull(theBoard[i])) {

            // rows are shifted down
            vector<vector<Cell>> tempBoard = this->theBoard;
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < width; ++k) {
                    theBoard[j+1][k].id = tempBoard[j][k].id;
                    theBoard[j+1][k].type = tempBoard[j][k].type;
                }
            }

            // first row becomes an empty row
            for (auto &cell : theBoard[0]) {
                cell.type = ' ';
                cell.id = 0;
            }

            // increment rows cleared
            rowsCleared++;
        }
    }
    return rowsCleared;
}

vector<int> Board::getIDs() {
    // insert ids to a set
    set<int> idSet;
    for (auto row : theBoard) {
        for (auto cell : row) {
            idSet.insert(cell.id);
        }
    }

    // remove 0 since 0 is the ID of an empty cell
    idSet.erase(0);

    // convert to a vector
    vector<int> idVec(idSet.begin(), idSet.end());
    return idVec;
}

ostream &operator<<(std::ostream &out, const Board &b) {
    for (auto row : b.theBoard) {
        for (auto cell : row) {
            if (cell.type == ' ') {
                out << '-';
            } else {
                out << cell.type;
            }
        }
        out << endl;
    }
    return out;
}
