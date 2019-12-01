#include "game_state.h"
#include "player.h"
using namespace std;

GameState::GameState() : p1{make_shared<Player>("sequence1.txt")}, p2{make_shared<Player>("sequence2.txt")}, turn{0},
td{make_shared<TextDisplay>()} {
    this->attachToSubjects();
    td->print();
}

void GameState::rotate(int reps, string dir) {
    for (int i = 0; i < reps; i++) {
        turn % 2 == 0 ? p1->rotate(dir) : p2->rotate(dir);
    }

    if(turn % 2 == 0){
        if(!p1->lowerIfHeavy()){
            p1->drop();
        }
    } else{
        if(!p2->lowerIfHeavy()){
            p2->drop();
        }
    }
}

void GameState::translate(int reps, int x, int y) {
    for (int i = 0; i < reps; i++) {
        turn % 2 == 0 ? p1->translate(x, y) : p2->translate(x, y);
    }
    if(turn % 2 == 0){
        if(!p1->lowerIfHeavy()){
            p1->drop();
        }
    } else{
        if(!p2->lowerIfHeavy()){
            p2->drop();
        }
    }
}

void GameState::drop(int multiplier) {
    for (int i = 0; i < multiplier; i++) {
        try {
            turn % 2 == 0 ? p1->drop() : p2->drop();
        } catch (string s) {
            // game over for current player.
            if (turn % 2 == 0) {
                throw 2;
            } else {
                throw 1;
            }
        }
    }
    turn++;
}

void GameState::levelUp(int multiplier) {
    for (int i = 0; i < multiplier; i++) {
        turn % 2 == 0 ? p1->levelUp() : p2->levelUp();
    }
}

void GameState::levelDown(int multiplier) {
    for (int i = 0; i < multiplier; i++) {
        turn % 2 == 0 ? p1->levelDown() : p2->levelDown();
    }
}

void GameState::noRandom(std::string file) {
    turn % 2 == 0 ? p1->noRandom(file) : p2->noRandom(file);
}

void GameState::setRandom() {
    turn % 2 == 0 ? p1->setRandom() : p2->setRandom();
}

void GameState::replaceBlock(char block) {
    turn % 2 == 0 ? p1->replaceBlock(block) : p2->replaceBlock(block);
}

void GameState::notify(Subject<Info> &whoFrom) {
    Info info = whoFrom.getInfo();
    info.player = turn % 2 == 0 ? 1 : 2;
    info.score = turn % 2 == 0 ? p1->getScore() : p2->getScore();
    info.level = turn % 2 == 0 ? p1->getLevel() : p2->getLevel();
    td->update(info);
}

int GameState::getScore(int player) {
    if (player == 1) {
        return p1->getScore();
    } else {
        return p2->getScore();
    }
}

void GameState::attachToSubjects(){
    p1->attachObserver(this);
    turn++;
    p2->attachObserver(this);
    turn--;
}
