#include "level_two.h"
#include <cstdlib>
using namespace std;

Block LevelTwo::createBlock() {
    int num = rand() % 7;      // generates number from 0 to 6 inclusive

    if(num < 1){                // creates the appropriate block
        return IBlock{1};
    } else if(num < 2){
        return JBlock{1};
    } else if(num < 3){
        return LBlock{1};
    } else if(num < 4){
        return OBlock{1};
    } else if(num < 5){
        return TBlock{1};
    } else if(num < 6){
        return SBlock{1};
    } else{
        return ZBlock{1};
    }
}


