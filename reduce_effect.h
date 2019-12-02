#ifndef REDUCE_EFFECT_H
#define REDUCE_EFFECT_H

#include "abstract_effect.h"
using namespace std;

class ReduceEffect : public AbstractEffect{
    public:
        ReduceEffect(shared_ptr<AbstractPlayer> ab);
        ~ReduceEffect();
        int drop() override;
};

#endif
