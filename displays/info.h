#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>

struct Info {
    int row;
    int col;
    char type;
    int player;
    int level;
    int score;

    Info(int row, int col, char type, int player = -1, int level = -1, int score = -1) : row{row}, col{col}, type{type}, player{player}, level{level}, score{score} {}
};

#endif
