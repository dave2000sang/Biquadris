#ifndef ABSTRACT_EFFECT_H
#define ABSTRACT_EFFECT_H

#include "abstract_player.h"
using namespace std;

class AbstractEffect : public AbstractPlayer{
    protected:
        shared_ptr<AbstractPlayer> prevPlayer;
    public:
        AbstractEffect(shared_ptr<AbstractPlayer> ab);

        virtual bool blockIsValid() override;
        virtual void rotate(string dir) override;
        virtual bool translate(int x, int y) override;
        virtual void levelUp() override;
        virtual void levelDown() override;
        virtual void noRandom(string file) override;
        virtual void setRandom() override;
        virtual void toggleBlind(bool blind) override;
        virtual void replaceBlock(char c) override;
        virtual int drop() override;
        virtual bool lowerIfHeavy(bool isLeftRight) override;
        virtual int calculateScore(int linesCleared) override;
        virtual void updateFactory() override;
        void attachObserver(Observer<Info>* gs);

     // Getter Methods
        virtual int getScore() override;
        virtual void setScore(int s) override;
        virtual int getLevel() override;
        virtual Block getNextNextBlock() override;
};

#endif

