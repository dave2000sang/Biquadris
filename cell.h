#ifndef CELL_H
#define CELL_H
#include "displays/subject.h"
#include "displays/info.h"

struct Cell : public Subject {
    int row, col;
    int id;
    char type;      //type of block occupying this cell (I, J, *, ' ', ...)
    int player; // 1 or 2

    Info getInfo();
};


Info Cell::getInfo() {
    return Info(row, col, type, player);
}

#endif
