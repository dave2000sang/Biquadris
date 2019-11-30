#include "level_one.h"
#include <cstdlib>
using namespace std;

Block LevelOne::createBlock() {
    int num = rand() % 12;      // generates number from 0 to 11 inclusive

    if(num < 2){                // creates the appropriate block
        return IBlock{1};
    } else if(num < 4){
        return JBlock{1};
    } else if(num < 6){
        return LBlock{1};
    } else if(num < 8){
        return OBlock{1};
    } else if(num < 10){
        return TBlock{1};
    } else if(num < 11){
        return SBlock{1};
    } else{
        return ZBlock{1};
    }
}
