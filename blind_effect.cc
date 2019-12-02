#include "blind_effect.h"
using namespace std;

BlindEffect::BlindEffect(shared_ptr<AbstractPlayer> ab): AbstractEffect(ab){
    prevPlayer->toggleBlind(true);
}

BlindEffect::~BlindEffect(){}

int BlindEffect::drop(){
    prevPlayer->toggleBlind(false);
    return prevPlayer->drop();
}