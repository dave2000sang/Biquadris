#ifndef CELL_H
#define CELL_H

struct Cell{
    int row, col;
    int id;
    char type;      //type of block occupying this cell (I, J, *, ' ', ...)
};

#endif
