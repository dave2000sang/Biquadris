#include "game_state.h"
using namespace std;

GameState::GameState() : p1{make_unique<Player>(this)}, p2{make_unique<Player>(this)}, turn{0},
td{make_unique<TextDisplay>()} {}

void GameState::rotate(int reps, string dir) {
    turn % 2 == 0 ? p1.rotate(reps, dir) : p2.rotate(reps, dir);
    turn++;
}

void GameState::translate(int reps, int x, int y) {
    turn % 2 == 0 ? p1.translate(reps, x, y) : p2.translate(reps, x, y);
    turn++;
}

void GameState::drop() {
    turn % 2 == 0 ? p1.drop() : p2.drop();
}

void GameState::levelUp(int multiplier) {
    turn % 2 == 0 ? p1.levelUp(multiplier) : p2.levelUp(multiplier);
    turn++;
}

void GameState::levelDown(int multiplier) {
    turn % 2 == 0 ? p1.levelDown(multiplier) : p2.levelDown(multiplier);
    turn++;
}

void GameState::noRandom(std::string file) {
    turn % 2 == 0 ? p1.noRandom(file) : p2.noRandom(file);
    turn++;
}

void GameState::setRandom() {
    turn % 2 == 0 ? p1.setRandom() : p2.setRandom();
    turn++;
}

void GameState::replaceBlock(char block) {
    turn % 2 == 0 ? p1.replaceBlock(block) : p2.replaceBlock(block);
    turn++;
}

// restarts entire game
void GameState::restart() {
    turn = 0;
    p1.reset();
    p2.reset();
    p1 = make_unique<Player>();
    p2 = make_unique<Player>();
}

void GameState::updateTurn() {
    turn += 1;
}

void GameState::notify(Subject<Info> &whoFrom) {
    Info info = whoFrom.getInfo();
    info.player = turn % 2 == 0 ? 1 : 2;
    info.score = turn % 2 == 0 ? p1->getScore() : p2->getScore();
    info.level = turn % 2 == 0 ? p1->getLevel() : p2->getLevel();
    td->update(info);
}
