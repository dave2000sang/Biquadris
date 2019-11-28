#include "level_two.h"
#include <cstdlib>
using namespace std;

Block* LevelTwo::createBlock() override{
    int num = rand() % 7;      // generates number from 0 to 6 inclusive

    if(num < 1){                // creates the appropriate block
        return new Block{'I', 2};
    } else if(num < 2){
        return new Block{'J', 2};
    } else if(num < 3){
        return new Block{'L', 2};
    } else if(num < 4){
        return new Block{'O', 2};
    } else if(num < 5){
        return new Block{'T', 2};
    } else if(num < 6){
        return new Block{'S', 2};
    } else{
        return new Block{'Z', 2};
    }
}
