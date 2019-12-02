#ifndef HEAVY_EFFECT_H
#define HEAVY_EFFECT_H

#include "abstract_effect.h"
using namespace std;

class HeavyEffect : public AbstractEffect{
    public:
        HeavyEffect(shared_ptr<AbstractPlayer> ab);
        ~HeavyEffect();
        bool lowerIfHeavy(bool isLeftRight) override;
};

#endif
