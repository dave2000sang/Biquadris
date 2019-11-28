#include "level_zero.h"
#include "blocks/i_block.h"
#include "blocks/j_block.h"
#include "blocks/l_block.h"
#include "blocks/o_block.h"
#include "blocks/s_block.h"
#include "blocks/t_block.h"
#include "blocks/z_block.h"
using namespace std;

// Constructor sets the file and opens filestream
LevelZero::LevelZero(string fileName): file{fileName}{
    this->in.open(fileName);
}

// Reads a char from the filestream and returns corresponding block
Block LevelZero::createBlock() override{
    char c = in.get();
    if(in.fail()){
        // Restarts from beginning of file if the end is reached
        this->in.open(this->file);
        c = in.get();
    }

    if(c == 'I'){
        return IBlock{0};
    } else if(c == 'J'){
        return new JBlock{0};
    } else if(c == 'L'){
        return new LBlock{0};
    } else if(c == 'O'){
        return new OBlock{0};
    } else if(c == 'S'){
        return new SBlock{0};
    } else if(c == 'T'){
        return new TBlock{0};
    } else if(c == 'Z'){
        return new ZBlock{0};
    }
}