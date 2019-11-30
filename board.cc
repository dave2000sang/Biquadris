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

vector<vector<bool>> Board::boardSpace(){
    vector<vector<bool>> boolBoard;

    for(auto row : theBoard){
        vector<bool> boolRow;
        for(auto cell : row){
            if(cell.type == ' '){
                boolRow.emplace_back(false);
            }else{
                boolRow.emplace_back(true);
            }
        }
        boolBoard.emplace_back(boolRow);
    }
    return boolBoard;
}

void Board::dropStar() {
    bool flag = false;
    for (int i = height - 1; i >= 0; i++) {
        Cell &curCell = theBoard[i][5];
        if (curCell.type == ' ') {
            curCell.type = '*';
            curCell.type = 0;
            flag = true;
        }
    }
    if (!flag) {
        throw "Game Over";
    }
}

void Board::erase(const Block b) {
    for (int i = 0; i < b.h; i++) {
        for (int j = 0; j < b.w; j++) {
            if (b.cells[i][j]) {
                theBoard[b.y+i][b.x+j].type = ' ';
                theBoard[b.y+i][b.x+j].id = 0;
            }
        }
    }
}

void Board::draw(const Block b, int ID) {
    for (int i = 0; i < b.h; i++) {
        for (int j = 0; j < b.w; j++) {
            if (b.cells[i][j]) {
                theBoard[b.y+i][b.x+j].type = b.type;
                theBoard[b.y+i][b.x+j].id = ID;
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
