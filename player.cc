#include "player.h"
#include "block_factory/level_zero.h"
#include "block_factory/level_one.h"
#include "block_factory/level_two.h"
#include "block_factory/level_three.h"
#include "block_factory/level_four.h"
#include <exception>
#include <iostream>

Player::Player(string fileName, Observer<Info> * gs): blockID{1}, score{0}, level{0}, starCounter{0}{
    levelZeroFile = fileName;
    board = make_unique<Board>();
    board->init(gs);
    blockFactory = make_unique<LevelZero>(fileName);
    nextBlock = blockFactory->createBlock();
    nextNextBlock = blockFactory->createBlock();
    board->draw(nextBlock, blockID);
}

bool Player::blockIsValid(){
    vector<vector<Cell>> theBoard = board->getBoard();
    vector<vector<bool>> blockBools = nextBlock.getCells();
    int x = nextBlock.getX();
    int y = nextBlock.getY();
    int width = nextBlock.getW();
    int height = nextBlock.getH();

    for(int row = height - 1; row >= 0; --row){
        for(int col = 0; col < width; ++col){
            if(blockBools[row][col] && (theBoard[y - height + row + 1][x + col].type != ' ')){
                if(theBoard[y - height + row + 1][x + col].id != blockID){
                    return false;
                }
            }
        }
    }
    return true;
}

void Player::rotate(string dir){
    Block temp = nextBlock;
    if(!(nextBlock.rotate(dir) && blockIsValid())){
        nextBlock = temp;
    } else{
        board->erase(temp);
        board->draw(nextBlock, blockID);
    }
}

void Player::translate(int x, int y){
    Block temp = nextBlock;
    if(!(nextBlock.translate(x, y) && blockIsValid())){
        nextBlock = temp;
    } else{
        board->erase(temp);
        board->draw(nextBlock, blockID);
    }
}

void Player::updateFactory(){
    starCounter = 0;
    if(level == 4){
        blockFactory = make_unique<LevelFour>();
    } else if(level == 3){
        blockFactory = make_unique<LevelThree>();
    } else if(level == 2){
        blockFactory = make_unique<LevelTwo>();
    } else if(level == 1){
        blockFactory = make_unique<LevelOne>();
    } else{
        blockFactory = make_unique<LevelZero>(levelZeroFile);
    }
}

void Player::levelUp(){
    if(level < 4){
        level++;
        updateFactory();
    }
}

void Player::levelDown(){
    if(level > 0){
        level--;
        updateFactory();
    }
}

void Player::noRandom(string file){
    blockFactory->setFile(file);
}

void Player::setRandom(){
    board->erase(nextBlock);
    blockFactory->setRandom();
    board->draw(nextBlock, blockID);
}

void Player::replaceBlock(char c){
    board->erase(nextBlock);
    nextBlock = blockFactory->specificBlock(c, level);
    board->draw(nextBlock, blockID);
}

int Player::getScore(int linesCleared){
    vector<int> activeIds = board->getIDs();
    int score = 0, levelsCleared = 0;

    cout << "getIDs: ";
    for(auto anID : activeIds){
        cout << anID << " ";
    }
    cout << endl;

    vector<BlockInfo> newActives;
    for(auto someBlockInfo : activeBlocks){
        bool found = false;
        for(auto someID : activeIds){
            if(someID == someBlockInfo.id){
                found = true;
            }
        }
        if(found){
            newActives.emplace_back(someBlockInfo);
        } else{
            score +=  (1 + someBlockInfo.level) * (1 + someBlockInfo.level);
        }
    }

    if(linesCleared > 0){
        score += (linesCleared + level) * (linesCleared + level);
    }

    
    activeBlocks = newActives;

    return score;
}

void Player::drop(){
    BlockInfo bi{blockID, nextBlock.getLevel()};
    activeBlocks.emplace_back(bi);

    board->erase(nextBlock);
    int linesCleared = board->drop(nextBlock, blockID);
    blockID++;
    score += this->getScore(linesCleared);

    nextBlock = nextNextBlock;
    nextNextBlock = blockFactory->createBlock();

    if(!blockIsValid()){
        throw "Game Over";
    }

    board->draw(nextBlock, blockID);

    if(level == 4){
        if(linesCleared == 0){
            starCounter++;
        } else{
            starCounter = 0;
        }

        if(starCounter % 5 == 0){
        board->dropStar();
        }
    }
}

int Player::getScore(){
    return score;
}

int Player::getLevel(){
    return level;
}

Block Player::getNextNextBlock(){
    return nextNextBlock;
}

ostream &operator<<(std::ostream &out, const Player &p) {
    out << "Level: " << p.level << endl;
    out << "Score: " << p.score << endl;
    out << "blockID: " << p.blockID << endl;
    out << "starCounter: " << p.starCounter << endl;
    out << "Active Blocks:";
    for(int i = 0; i < p.activeBlocks.size(); i++){
        out << p.activeBlocks[i].id << ", ";
    }
    out << endl;
    out << "***********" << endl;
    out << *(p.board) << endl;
    //out << "***********" << endl;
    //out << p.nextBlock << endl;

    return out;
}

void Player::attachObserver(Observer<Info>* gs){
    board->attachObserver(gs);
}