#ifndef FORCE_EFFECT_H
#define FORCE_EFFECT_H

#include "abstract_effect.h"
using namespace std;

class ForceEffect : public AbstractEffect{
    public:
        ForceEffect(shared_ptr<AbstractPlayer> ab, char c);
        void replaceBlock(char c) override;
};

#endif