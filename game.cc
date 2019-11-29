#include "game.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Game::Game() {
    this->play();
}

void Game::play() {
    // player 1 goes first ?
    bool readFile = false;
    fstream fs;
    while (true) {
        string input;
        if (readFile && fs.is_open()) {
            if (!(fs << input)) {
                readFile = false;
                fs.close();
            }
        } else {
            if (!(cin >> input)) {
                cout << "Invalid command" << endl;
                continue;
            }
        }
        int multiplier = cmdInterp.parseMultiplier(input);
        CommandType cmd = cmdInterp.parseCommand(input);
        bool invalidInput = false;
        string file;        // for use by sequence and noRandom
        if (multiplier == 0) {
            continue;
        }
        switch (cmd) {
            case CommandType::left:
                game.translate(multiplier, -1, 0);
                break;
            case CommandType::right:
                game.translate(multiplier, 1, 0);
                break;
            case CommandType::down:
                game.translate(multiplier, 0, 1);
                break;
            case CommandType::clockwise:
                game.rotate(multiplier, "cw");
                break;
            case CommandType::counterclockwise:
                game.rotate(multiplier, "ccw");
                break;
            case CommandType::drop:
                game.drop();
                break;
            case CommandType::levelup:
                game.levelUp(multiplier);
                break;
            case CommandType::leveldown:
                game.levelDown(multiplier);
                break;
            case CommandType::norandom:
                if (cin >> file) {
                    game.noRandom(file);
                } else {
                    invalidInput = true;
                }
                break;
            case CommandType::random:
                game.setRandom();
                break;
            case CommandType::sequence:
                if (cin >> file) {
                    readFile = true;
                    fs.open(file);
                } else {
                    invalidInput = true;
                }
                break;
            case CommandType::I:
                game.replaceBlock('I');
                break;
            case CommandType::J:
                game.replaceBlock('J');
                break;
            case CommandType::L:
                game.replaceBlock('L');
                break;
            case CommandType::O:
                game.replaceBlock('O');
                break;
            case CommandType::S:
                game.replaceBlock('S');
                break;
            case CommandType::Z:
                game.replaceBlock('Z');
                break;
            case CommandType::T:
                game.replaceBlock('T');
                break;
            case CommandType::restart:
                break;
            default:
                invalidInput = true;
        }
        if (invalidInput) {
            cout << "Invalid command" << endl;
            continue;
        }
        game.updateTurn();     // next player's turn

        // TODO : check game over condition
    }
}
