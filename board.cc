#include "board.h"
using namespace std;

void Board::init(int width, int height) {
    theBoard.clear();
    this->width = width;
    this->height = height;

    theBoard = vector<vector<Cell>> (height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Cell newCell = Cell{i, j, 0, ' '};
            theBoard[i].emplace_back(newCell);
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

int Board::drop(Block &block, int ID) { // TODO: get type from block
    int x = block.x;
    int y = block.y - block.h + 1;
    int w = block.w;
    int h = block.h;
    char type = block.type;

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
                theBoard[i + y][j + x].notifyObservers();
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
                    theBoard[j + 1][k].notifyObservers();
                }
            }

            // first row becomes an empty row
            for (auto &cell : theBoard[0]) {
                cell.type = ' ';
                cell.id = 0;
                cell.notifyObservers();
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

vector<vector<Cell>> Board::getBoard(){
    return theBoard;
}

void Board::dropStar() {
    bool flag = false;
    for (int i = height - 1; i >= 0; i++) {
        Cell &curCell = theBoard[i][5];
        if (curCell.type == ' ') {
            curCell.type = '*';
            curCell.type = 0;
            curCell.notifyObservers();
            flag = true;
        }
    }
    if (!flag) {
        throw "Game Over";
    }
}

void Board::erase(const Block b) {
    for (int row = b.h - 1; row >= 0; --row) {
        for (int col = 0; col < b.w; ++col) {
            if (b.cells[row][col]) {
                theBoard[b.y - b.h + row + 1][b.x+col].type = ' ';
                theBoard[b.y - b.h + row + 1][b.x+col].id = 0;
                theBoard[b.y - b.h + row + 1][b.x+col].notifyObservers();
            }
        }
    }
}

void Board::draw(const Block b, int ID) {
    for (int row = b.h - 1; row >= 0; --row) {
        for (int col = 0; col < b.w; ++col) {
            if (b.cells[row][col]) {  
                theBoard[b.y - b.h + row + 1][b.x+col].type = b.type;
                theBoard[b.y - b.h + row + 1][b.x+col].id = ID;
                theBoard[b.y - b.h + row + 1][b.x+col].notifyObservers();
            }
        }
    }
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

void Board::attachObserver(Observer<Info>* gs){
    for(auto &row : theBoard){
        for(auto &aCell : row){
            aCell.attach(gs);
            aCell.notifyObservers();
        }
    }
}
