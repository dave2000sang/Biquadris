#include "game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

Game::Game(int startlevel, string file1, string file2, bool graphicsActive) : file1{file1}, file2{file2}, startlevel{startlevel}, game{make_shared<GameState>(startlevel, file1, file2, graphicsActive)}, highScore{0}, graphicsActive{graphicsActive} {
    game->attachToSubjects();
    game->td->print();
    game->gd->printGraphics();
    this->play();
}

void Game::play() {
    // player 1 goes first ?
    bool readFile = false;
    fstream fs;
    try {
        while (true) {
            string input;
            if (readFile && fs.is_open()) {
                if (!(fs >> input)) {
                    readFile = false;
                    fs.close();
                }
            } else {
                if (!(cin >> input)) {
                    if (cin.eof()) {
                        // Exit program
                        return;
                    }
                    cout << "Invalid command" << endl;
                    continue;
                }
            }
            int multiplier = cmdInterp.parseMultiplier(input); 
            vector<CommandType> cmdVec = cmdInterp.parseCommand(input);
            bool invalidInput = false;
            string file;        // for use by sequence and noRandom
            if (multiplier == 0) {
                continue;
            }
          
            for(auto cmd : cmdVec){
                switch (cmd) {
                    case CommandType::left:
                        game->translate(multiplier, -1, 0);
                        break;
                    case CommandType::right:
                        game->translate(multiplier, 1, 0);
                        break;
                    case CommandType::down:
                        game->translate(multiplier, 0, 1);
                        break;
                    case CommandType::clockwise:
                        game->rotate(multiplier, "cw");
                        break;
                    case CommandType::counterclockwise:
                        game->rotate(multiplier, "ccw");
                        break;
                    case CommandType::drop:
                        game->drop(multiplier);
                        highScore = max(highScore, game->getHighScore());
                        break;
                    case CommandType::levelup:
                        game->levelUp(multiplier);
                        break;
                    case CommandType::leveldown:
                        game->levelDown(multiplier);
                        break;
                    case CommandType::norandom:
                        if (cin >> file) {
                            game->noRandom(file);
                    } else {
                        invalidInput = true;
                    }
                    break;
                    case CommandType::random:
                        game->setRandom();
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
                        game->replaceBlock('I');
                        break;
                    case CommandType::J:
                        game->replaceBlock('J');
                        break;
                    case CommandType::L:
                        game->replaceBlock('L');
                        break;
                    case CommandType::O:
                        game->replaceBlock('O');
                        break;
                    case CommandType::S:
                        game->replaceBlock('S');
                        break;
                    case CommandType::Z:
                        game->replaceBlock('Z');
                        break;
                    case CommandType::T:
                        game->replaceBlock('T');
                        break;
                    case CommandType::restart:
                        this->restart();
                        break;
                    case CommandType::macro:
                    {
                        vector<CommandType> macroList;
                        string nextCmd, macroName;
                        if(cin >> macroName){
                            while(cin >> nextCmd){
                                int newCmdMultiplier = cmdInterp.parseMultiplier(nextCmd);
                                vector<CommandType> newCmdVec = cmdInterp.parseCommand(nextCmd);
                                for(auto nestedCmd : newCmdVec){
                                    for(int i = 0; i < newCmdMultiplier; i++){
                                        macroList.emplace_back(nestedCmd);
                                    }
                                }
                                if(cin.peek() == 10){
                                    break;
                                }
                            }
                            cmdInterp.addMacro(macroName, macroList);
                        }
                        break;
                    }
                    default:
                        invalidInput = true;
                }
            }
            if (invalidInput) {
                cout << "Invalid command" << endl;
                continue;
            }

            game->td->print();

            // TODO : check game over condition
        }
    } catch(int whoWon) {
        cout << "Player " << whoWon << " Wins!" << endl;
        cout << "High Score = " << highScore << endl;
        this->restart();
    }
}

void Game::restart() {
    game.reset(new GameState{startlevel, file1, file2, graphicsActive});
    game->attachToSubjects();
    game->td->print();
    game->gd->printGraphics();
    this->play();
}
