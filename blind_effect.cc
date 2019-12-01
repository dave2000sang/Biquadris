#include "blind_effect.h"
using namespace std;

BlindEffect::BlindEffect(shared_ptr<AbstractPlayer> ab): AbstractEffect(ab){
    cout << "In BlindEffect const" << endl;
    prevPlayer->toggleBlind(true);  
    cout << "After toggleBlind" << endl;
}

BlindEffect::~BlindEffect(){}

int BlindEffect::drop(){
    prevPlayer->toggleBlind(false);
    return prevPlayer->drop();
}