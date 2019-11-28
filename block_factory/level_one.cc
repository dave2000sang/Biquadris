#include "level_one.h"
#include <cstdlib>
using namespace std;

Block* LevelOne::createBlock() override{
    int num = rand() % 12;      // generates number from 0 to 11 inclusive

    if(num < 2){                // creates the appropriate block
        return new Block{'I', 1};
    } else if(num < 4){
        return new Block{'J', 1};
    } else if(num < 6){
        return new Block{'L', 1};
    } else if(num < 8){
        return new Block{'O', 1};
    } else if(num < 10){
        return new Block{'T', 1};
    } else if(num < 11){
        return new Block{'S', 1};
    } else{
        return new Block{'Z', 1};
    }
}
