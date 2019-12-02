#include "heavy_effect.h"
using namespace std;

HeavyEffect::HeavyEffect(shared_ptr<AbstractPlayer> ab): AbstractEffect(ab){}

HeavyEffect::~HeavyEffect(){}

bool HeavyEffect::lowerIfHeavy(bool isLeftRight){
    if(isLeftRight && !prevPlayer->translate(0, 2)){
            return false;
    }
    return prevPlayer->lowerIfHeavy(isLeftRight);
}
