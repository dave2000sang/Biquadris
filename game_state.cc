#include "game_state.h"
#include "player.h"
#include "blind_effect.h"
#include "heavy_effect.h"
#include "force_effect.h"
using namespace std;

GameState::GameState(int startlevel, string file1, string file2, bool graphicsActive) : startlevel{startlevel}, curhighscore{0},

    p1{make_shared<Player>(file1, startlevel)}, p2{make_shared<Player>(file2, startlevel)}, turn{0}, td{make_unique<TextDisplay>()}, gd{make_unique<GraphicsDisplay>(graphicsActive)}, graphicsActive{graphicsActive} {}

void GameState::rotate(int reps, string dir) {
    for (int i = 0; i < reps; i++) {
        turn % 2 == 0 ? p1->rotate(dir) : p2->rotate(dir);
    }

    if(turn % 2 == 0){
        if(!p1->lowerIfHeavy(false)){
            if(p1->drop() >= 2){
                this->makeEffect(2);
            }
        }
    } else{
        if(!p2->lowerIfHeavy(false)){
            if(p2->drop() >= 2){
                this->makeEffect(2);
            }
        }
    }
}

void GameState::translate(int reps, int x, int y) {
    for (int i = 0; i < reps; i++) {
        turn % 2 == 0 ? p1->translate(x, y) : p2->translate(x, y);
    }
    if(turn % 2 == 0){
        if(!p1->lowerIfHeavy(y == 0 && x != 0)){
            this->drop(1);
        }
    } else{
        if(!p2->lowerIfHeavy(y == 0 && x != 0)){
            this->drop(1);
        }
    }
}

void GameState::drop(int multiplier) {
    for (int i = 0; i < multiplier; i++) {
        try {
            if(turn % 2 == 0){
                if(p1->drop() >= 2){
                    this->makeEffect(2);
                }
            } else{
                if(p2->drop() >= 2){
                    this->makeEffect(2);
                }
            }
            curhighscore = max(curhighscore, max(p1->getScore(), p2->getScore()));
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
    gd->update(info);
}

void GameState::attachToSubjects(){
    p1->attachObserver(this);
    turn++;
    p2->attachObserver(this);
    turn--;
}


int GameState::getHighScore() {
    return curhighscore;
}

void GameState::makeEffect(int targetPlayer){
    turn++;
    targetPlayer = (turn) % 2 + 1;
    cout << "Give the opponent an effect! (blind, heavy, I, L, O, S, Z, T, J)" << endl; 
    if(targetPlayer == 1){
        string response;
        while(cin >> response){
            if(response == "blind"){
                cout << "You blinded the opponent" << endl;
                p1 = make_shared<BlindEffect>(p1);
                break;
            } else if(response == "heavy"){
                cout << "You made the opponent's blocks heavy" << endl;
                p1 = make_shared<HeavyEffect>(p1);
                break;
            } else if (response == "I" ||response == "J" ||response == "L" ||response == "O" 
            || response == "S" ||response == "Z" || response == "T" ){
                char tempChar = response.at(0);
                cout << "The opponent's next block is now " << tempChar << endl;
                p1 = make_shared<ForceEffect>(p1, tempChar);
                break;
            } else{
                 cout << "Give the opponent an effect! (blind, heavy, I, L, O, S, Z, T, J)" << endl; 
            }
        }
    } else{
        string response;
        while(cin >> response){
            if(response == "blind"){
                cout << "You blinded the opponent" << endl;
                p2 = make_shared<BlindEffect>(p2);
                break;
            } else if(response == "heavy"){
                cout << "You made the opponent's blocks heavy" << endl;
                p2 = make_shared<HeavyEffect>(p2);
                break;
            } else if (response == "I" ||response == "J" ||response == "L" ||response == "O" 
            || response == "S" ||response == "Z" || response == "T" ){
                char tempChar = response.at(0);
                cout << "The opponent's next block is now " << tempChar << endl;
                p2 = make_shared<ForceEffect>(p2, tempChar);
                break;
            } else{
                 cout << "Give the opponent an effect! (blind, heavy, I, L, O, S, Z, T, J)" << endl; 
            }
        }
    }
    turn --;
}
