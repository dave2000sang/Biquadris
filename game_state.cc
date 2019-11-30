#include "game_state.h"
using namespace std;

GameState::GameState() : p1{make_unique<Player>()}, p2{make_unique<Player>()}, turn{0} {}

void GameState::rotate(int reps, string dir) {
    for (int i = 0; i < reps; i++) {
        turn % 2 == 0 ? p1->rotate(dir) : p2->rotate(dir);
    }
    turn++;
}

void GameState::translate(int reps, int x, int y) {
    for (int i = 0; i < reps; i++) {
        turn % 2 == 0 ? p1->translate(x, y) : p2->translate(x, y);
    }
    turn++;
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
}

void GameState::levelUp(int multiplier) {
    for (int i = 0; i < multiplier; i++) {
        turn % 2 == 0 ? p1->levelUp() : p2->levelUp();
    }
    turn++;
}

void GameState::levelDown(int multiplier) {
    for (int i = 0; i < multiplier; i++) {
        turn % 2 == 0 ? p1->levelDown() : p2->levelDown();
    }
    turn++;
}

void GameState::noRandom(std::string file) {
    turn % 2 == 0 ? p1->noRandom(file) : p2->noRandom(file);
    turn++;
}

void GameState::setRandom() {
    turn % 2 == 0 ? p1->setRandom() : p2->setRandom();
    turn++;
}

void GameState::replaceBlock(char block) {
    turn % 2 == 0 ? p1->replaceBlock(block) : p2->replaceBlock(block);
    turn++;
}

void GameState::updateTurn() {
    turn += 1;
}
