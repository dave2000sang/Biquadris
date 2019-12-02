#include "force_effect.h"
using namespace std;

ForceEffect::ForceEffect(shared_ptr<AbstractPlayer> ab, char c): AbstractEffect(ab){
    prevPlayer->replaceBlock(c);
}

void ForceEffect::replaceBlock(char c){
    prevPlayer->replaceBlock(c);
}
