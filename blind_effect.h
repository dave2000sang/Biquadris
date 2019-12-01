#ifndef BLIND_EFFECT_H
#define BLIND_EFFECT_H

#include "abstract_effect.h"
using namespace std;

class BlindEffect : public AbstractEffect{
    public:
        BlindEffect(shared_ptr<AbstractPlayer> ab);
        ~BlindEffect();
        int drop() override;
};

#endif