#include "level_zero.h"
#include <iostream>
#include <exception>
using namespace std;

// Constructor sets the file and opens filestream
LevelZero::LevelZero(string fileName){
    try{
    this->file = fileName;
    this->in.open(this->file);
    } catch(bad_alloc& b){
        cout << "Error: file " << this->file << " was not found." << endl;
    }
}

// Reads a char from the filestream and returns corresponding block
Block LevelZero::createBlock() {
    try{
    char c;
    do{
        c = in.get();
    } while(c == 10 || c == 32);
    
    if(in.eof()){
        // Restarts from beginning of file if the end is reached
        in.close();
        in.clear();
        this->in.open(this->file);
        c = in.get();
    }

    if(c == 'I'){
        return IBlock{0};
    } else if(c == 'J'){
        return JBlock{0};
    } else if(c == 'L'){
        return LBlock{0};
    } else if(c == 'O'){
        return OBlock{0};
    } else if(c == 'S'){
        return SBlock{0};
    } else if(c == 'T'){
        return TBlock{0};
    } else if(c == 'Z'){
        return ZBlock{0};
    }
    
    } catch(bad_alloc& b){
        cout << "Error: file " << this->file << " was not found." << endl;
    }
}

