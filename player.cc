#include "player.h"
#include "block_factory/level_zero.h"
#include "block_factory/level_one.h"
#include "block_factory/level_two.h"
#include "block_factory/level_three.h"
#include "block_factory/level_four.h"
#include <exception>

Player::Player(string fileName): blockID{1}, score{0}, level{0}, starCounter{0}{
    levelZeroFile = fileName;
    board = make_unique<Board>();
    board->init(11, 18);
    blockFactory = make_unique<LevelZero>(fileName);
    nextBlock = blockFactory->createBlock();
    board->draw(nextBlock, blockID);
}

bool Player::blockIsValid(){
    board->erase(nextBlock);
    vector<vector<bool>> boardBools = board->boardSpace();
    vector<vector<bool>> blockBools = nextBlock.getCells();
    int x = nextBlock.getX();
    int y = nextBlock.getY();
    int width = nextBlock.getW();
    int height = nextBlock.getH();

    for(int row = height - 1; row >= 0; --row){
        for(int col = 0; col < width; ++col){
            if(blockBools[row][col] && boardBools[y - height + row + 1][x + col]){
                board->draw(nextBlock, blockID);
                return false;
            }
        }
    }
    board->draw(nextBlock, blockID);
    return true;
}

void Player::rotate(string dir){
    Block temp = nextBlock;
    if(!(nextBlock.rotate(dir) && blockIsValid())){
        nextBlock = temp;
    } else{
        board->erase(temp);
        board->draw(nextBlock, this->blockID);
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
    blockFactory->setRandom();
}

void Player::replaceBlock(char c){
    board->erase(nextBlock);
    nextBlock = blockFactory->specificBlock(c, level);
    board->draw(nextBlock, blockID);
}

int Player::getScore(int linesCleared){
    vector<int> activeIds = board->getIDs();
    int score = 0, levelsCleared = 0;
    bool found = false;

    for(int i = 0; i < activeBlocks.size(); ++i){
        for(int j = 0; j < activeIds.size(); ++j){
            if(activeIds[j] == activeBlocks[i].id){
                found = true;
            }
        }

        if(!found){
            levelsCleared += activeBlocks[i].level;
        } else{
            found = false;
        }
    }

    return (linesCleared + level) * (linesCleared + level) + 
        (levelsCleared + 1) * (levelsCleared + 1);
}

void Player::drop(){
    BlockInfo bi{blockID, level};
    activeBlocks.emplace_back(bi);
    blockID++;

    int linesCleared = board->drop(nextBlock, level);
    board->erase(nextBlock);
    score += this->getScore(linesCleared);
    nextBlock = blockFactory->createBlock();
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
    }

    if(starCounter % 5 == 0){
        board->dropStar();
    }
}

int Player::getScore(){
    return score;
}

int Player::getLevel(){
    return level;
}