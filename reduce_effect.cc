#include "reduce_effect.h"
#include <iostream>
using namespace std;

ReduceEffect::ReduceEffect(shared_ptr<AbstractPlayer> ab): AbstractEffect(ab){}

ReduceEffect::~ReduceEffect(){}

int ReduceEffect::drop(){
    int oldScore = prevPlayer->getScore();
    int linesCleared = prevPlayer->drop();
    int newScore = prevPlayer->getScore();
    prevPlayer->setScore((oldScore + (newScore - oldScore) / 2));
    return linesCleared;
}
