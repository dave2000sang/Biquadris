#ifndef CELL_H
#define CELL_H
#include "displays/info.h"
#include "displays/subject.h"

struct Cell : public Subject<Info> {
    int row, col;
    int id;
    char type;      //type of block occupying this cell (I, J, *, ' ', ...)

    Cell(int r, int c, int i, char t) : row{r}, col{c}, id{i}, type{t} {}
    Info getInfo() const override {
        return Info{row, col, type};
    }
};

#endif
