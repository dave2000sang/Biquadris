#include "level_three.h"
#include <cstdlib>
using namespace std;

Block* LevelThree::createBlock() override{
    int num = rand() % 9;      // generates number from 0 to 8 inclusive

    if(num < 1){                // creates the appropriate block
        return new Block{'I', 3};
    } else if(num < 2){
        return new Block{'J', 3};
    } else if(num < 3){
        return new Block{'L', 3};
    } else if(num < 4){
        return new Block{'O', 3};
    } else if(num < 5){
        return new Block{'T', 3};
    } else if(num < 7){
        return new Block{'S', 3};
    } else{
        return new Block{'Z', 3};
    }
}
