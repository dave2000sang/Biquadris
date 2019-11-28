#include "level_zero.h"
using namespace std;

// Constructor sets the file and opens filestream
LevelZero::LevelZero(string fileName): file{fileName}{
    this->in.open(fileName);
    assure(this->in, fileName);
}

// Reads a char from the filestream and returns corresponding block
Block* LevelZero::createBlock() override{
    char c = in.get();
    if(in.fail()){
        // Restarts from beginning of file if the end is reached
        this->in.open(this->file);
        c = in.get();
    }

    Block* b = new Block(c, 0);
    return b;
}