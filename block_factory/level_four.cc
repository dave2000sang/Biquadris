#include "level_four.h"
#include <cstdlib>
using namespace std;

Block* LevelFour::createBlock() override{
    int num = rand() % 9;      // generates number from 0 to 8 inclusive

    if(num < 1){                // creates the appropriate block
        return new Block{'I', 4};
    } else if(num < 2){
        return new Block{'J', 4};
    } else if(num < 3){
        return new Block{'L', 4};
    } else if(num < 4){
        return new Block{'O', 4};
    } else if(num < 5){
        return new Block{'T', 4};
    } else if(num < 7){
        return new Block{'S', 4};
    } else{
        return new Block{'Z', 4};
    }
}
