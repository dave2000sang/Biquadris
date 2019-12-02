#include "level_four.h"
#include <cstdlib>
#include <exception>
#include <iostream>
using namespace std;

Block LevelFour::createBlock(){
    try{

    if(random){
        int num = rand() % 9;      // generates number from 0 to 8 inclusive

        if(num < 1){                // creates the appropriate block
            return IBlock{4};
        } else if(num < 2){
            return JBlock{4};
        } else if(num < 3){
            return LBlock{4};
        } else if(num < 4){
            return OBlock{4};
        } else if(num < 5){
            return TBlock{4};
        } else if(num < 7){
                return SBlock{4};
        } else{
            return ZBlock{4};
        }
    } else{
        char c;
        do{
            c = in.get();
        } while(c == 10 || c == 32);
    
        if(in.eof()){
            // Restarts from beginning of file if the end is reached
            in.close();
            in.clear();
            in.open(this->file);
            c = in.get();
        }

        if(c == 'I'){
            return IBlock{4};
        } else if(c == 'J'){
            return JBlock{4};
        } else if(c == 'L'){
            return LBlock{4};
        } else if(c == 'O'){
            return OBlock{4};
        } else if(c == 'S'){
            return SBlock{4};
        } else if(c == 'T'){
            return TBlock{4};
        } else if(c == 'Z'){
            return ZBlock{4};
        }
    }
    
    } catch(bad_alloc& b){
        cout << "Error: file " << this->file << " was not found." << endl;
    }
}

void LevelFour::setRandom() {
    this->random = true;
}

void LevelFour::setFile(string fileName) {
    try{

    this->file = fileName;
    this->random = false;
    this->in.open(this->file);

    } catch(bad_alloc& b){
        cout << "Error: file " << this->file << " was not found." << endl;
    }
}