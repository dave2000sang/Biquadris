#include "block_factory.h"
using namespace std;

void BlockFactory::setFile(string fileName){
    this->file = fileName;
}

void BlockFactory::setRandom(){}

Block BlockFactory::specificBlock(char c, int level){
    if(c == 'I'){
        return IBlock{level};
    } else if(c == 'J'){
        return JBlock{level};
    } else if(c == 'L'){
        return LBlock{level};
    } else if(c == 'T'){
        return TBlock{level};
    } else if(c == 'S'){
        return SBlock{level};
    } else if(c == 'Z'){
        return ZBlock{level};
    } else{
        return OBlock{level};
    } 
}


