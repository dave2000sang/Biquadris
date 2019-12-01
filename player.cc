#include "player.h"
#include "block_factory/level_zero.h"
#include "block_factory/level_one.h"
#include "block_factory/level_two.h"
#include "block_factory/level_three.h"
#include "block_factory/level_four.h"
#include <exception>
#include <iostream>

Player::Player(string fileName, int level): level{level}{
    this->blockID = 1;
    this->score = 0;
    this->starCounter = 0;
    levelZeroFile = fileName;
    board = make_shared<Board>();
    board->init();
    blockFactory = make_shared<LevelZero>(fileName);
    nextBlock = blockFactory->createBlock();
    nextNextBlock = blockFactory->createBlock();
    board->draw(nextBlock, blockID);
}

// Checks if the current "next block" is in a valid position, withhout collisions
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

// Rotates the next block, if it would end up in a valid position
void Player::rotate(string dir){
    Block temp = nextBlock;
    if(!(nextBlock.rotate(dir) && blockIsValid())){
        nextBlock = temp;
    } else{
        board->erase(temp);
        board->draw(nextBlock, blockID);
    }
}

// Translates the next block, if it would end up in a valid position
bool Player::translate(int x, int y){
    Block temp = this->nextBlock;
    if(!(this->nextBlock.translate(x, y) && this->blockIsValid())){
        this->nextBlock = temp;
        return false;
    } else{
        this->board->erase(temp);
        this->board->draw(this->nextBlock, blockID);
        return true;
    }
}

// Creates a new block factory based on the current level
void Player::updateFactory(){
    starCounter = 0;
    if(level == 4){
        blockFactory = make_shared<LevelFour>();
    } else if(level == 3){
        blockFactory = make_shared<LevelThree>();
    } else if(level == 2){
        blockFactory = make_shared<LevelTwo>();
    } else if(level == 1){
        blockFactory = make_shared<LevelOne>();
    } else{
        blockFactory = make_shared<LevelZero>(levelZeroFile);
    }
}

// Levels up the player and creates the corresponding block factory
void Player::levelUp(){
    if(level < 4){
        level++;
        updateFactory();
        board->updateLevel();
    }
}

// Levels down the player and creates the corresponding block factory
void Player::levelDown(){
    if(level > 0){
        level--;
        updateFactory();
        board->updateLevel();
    }
}

// Makes Levels 3 and 4 read input from a file, rather than randomly
void Player::noRandom(string file){
    blockFactory->setFile(file);
}

// Allows Levels 3 or 4 to randomly generate blocks again
void Player::setRandom(){
    board->erase(nextBlock);
    blockFactory->setRandom();
    board->draw(nextBlock, blockID);
}

// Replaces the next block with the type of block specified
void Player::replaceBlock(char c){
    board->erase(nextBlock);
    nextBlock = blockFactory->specificBlock(c, level);
    board->draw(nextBlock, blockID);
}

// Helper function to calculate the score based on lines and blocks cleared
int Player::calculateScore(int linesCleared){
    vector<int> activeIds = board->getIDs();
    int score = 0, levelsCleared = 0;

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

// Drops the next block into the board, updates score, and readies the next block
int Player::drop(){
    BlockInfo bi{blockID, nextBlock.getLevel()};
    activeBlocks.emplace_back(bi);

    board->erase(nextBlock);
    int linesCleared = board->drop(nextBlock, blockID);
    blockID++;
    score += this->calculateScore(linesCleared);

    nextBlock = nextNextBlock;
    nextNextBlock = blockFactory->createBlock();

    if(!blockIsValid()){
        cout << "before throw game over " << endl;
        throw string("Game Over");
    }

    board->draw(nextBlock, blockID);

    if(level == 4){
        if(linesCleared == 0){
            starCounter++;
        } else{
            starCounter = 0;
        }

        if(starCounter % 5 == 0 && starCounter > 0){
            board->dropStar();
        }
    }
    return linesCleared;
}

// Getter for score
int Player::getScore(){
    return score;
}

// Getter for level
int Player::getLevel(){
    return level;
}

// Getter for nextNextBlock
Block Player::getNextNextBlock(){
    return nextNextBlock;
}

// Lowers the block if it is heavy, returns false if not possible.
bool Player::lowerIfHeavy(bool isLeftRight){
    if(level >= 3){
        return this->translate(0,1);
    }
    return true;
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

void Player::toggleBlind(bool blind){
    board->toggleBlind(blind);
}
