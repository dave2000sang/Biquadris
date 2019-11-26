#include "board.h"
using namespace std;

void Board::drop(Block &block) {
    // TODO
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
