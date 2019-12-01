#include "abstract_effect.h"

AbstractEffect::AbstractEffect(shared_ptr<AbstractPlayer> ab): prevPlayer{ab}{}

bool AbstractEffect::blockIsValid(){
    return prevPlayer->blockIsValid();
}

void AbstractEffect::rotate(string dir){
    prevPlayer->rotate(dir);
}

bool AbstractEffect::translate(int x, int y){
    return prevPlayer->translate(x, y);
}

void AbstractEffect::levelUp(){
    prevPlayer->levelUp();
}

void AbstractEffect::levelDown(){
    prevPlayer->levelDown();
}

void AbstractEffect::noRandom(string file){
    prevPlayer->noRandom(file);
}

void AbstractEffect::setRandom(){
    prevPlayer->setRandom();
}

void AbstractEffect::replaceBlock(char c){
    prevPlayer->replaceBlock(c);
}

int AbstractEffect::drop(){
    return prevPlayer->drop();
}

bool AbstractEffect::lowerIfHeavy(bool isLeftRight){
    return prevPlayer->lowerIfHeavy(isLeftRight);
}

int AbstractEffect::calculateScore(int linesCleared){
    prevPlayer->calculateScore(linesCleared);
}

void AbstractEffect::updateFactory(){
    prevPlayer->updateFactory();
}


int AbstractEffect::getScore(){
    return prevPlayer->getScore();
}

int AbstractEffect::getLevel(){
    return prevPlayer->getLevel();
}

Block AbstractEffect::getNextNextBlock(){
    return prevPlayer->getNextNextBlock();
}

void AbstractEffect::toggleBlind(bool blind){
    prevPlayer->toggleBlind(blind);
}

void AbstractEffect::attachObserver(Observer<Info>* gs){
    prevPlayer->attachObserver(gs);
}
