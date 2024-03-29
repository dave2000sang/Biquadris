#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>
#include "../blocks/block.h"

struct Info {
    int row;
    int col;
    char type;
    int player;
    int level;
    int score;
    bool hidden;
    Block NNB;

    Info(int row, int col, char type, bool hidden, int player = -1, int level = -1, int score = -1, Block NNB = Block()) : row{row}, col{col}, type{type}, hidden{hidden}, player{player}, level{level}, score{score}, NNB{NNB} {}
};

#endif
