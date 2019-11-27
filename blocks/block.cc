#include "block.h"
#include <iostream>
using namespace std;

Block::Block(int x, int y, int w, int h, int level, char type) : x{x}, y{y}, w{w}, h{h}, level{level}, type{type} {
    // initialize with empty cells
    for (int i = 0; i < h; i++) {
        vector<bool> v;
        for (int j = 0; j < w; j++) {
            v.push_back(false);
        }
        cells.push_back(v);
    }
}

Block::~Block() {}

int Block::getX() {
    return x;
}

int Block::getY() {
    return y;
}

bool Block::rotate(string dir) {
    // check if rotation is valid
    int x2 = x + h - 1;
    int y2 = y - w + 1;
    if (y2 < 0 || x2 > 11) {
        return false;
    }

    // transpose cells
    vector<bool> tmp(h, false);
    vector<vector<bool>> transposed(w, tmp);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            transposed[j][i] = cells[i][j];
        }
    }
    swap(w, h);
    cells = transposed;
    if (dir == "cw") {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w/2; j++) {
                swap(cells[i][j], cells[i][w-j-1]);
            }
        }
    } else {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h/2; j++) {
                swap(cells[j][i], cells[h-j-1][i]);
            }
        }
    }
    return true;
}

bool Block::translate(int x, int y) {
    int x2 = this->x + x;
    int y2 = this->y + y;
    // check if valid translate
    if (x2 >= 0 && y2 - (h-1) >= 0 && x2 + w <= 11 && y2 <= 18) {
        this->x = x2;
        this->y = y2;
        return true;
    }
    return false;
}

// FOR TESTING
ostream &operator<<(ostream &out, const Block &b) {
    // int w = b.cells.size();
    // int h = b.cells[0].size();
    for (int i = 0; i < b.h; i++) {
        for (int j = 0; j < b.w; j++) {
            if (b.cells[i][j]) {
                out << "1";
            }
            else {
                out << "0";
            }
        }
        out << endl;
    }
    return out;
}
