#include "player.h"

Player::Player(string fileName): blockID{0}, score{0}, level{0}, 
starCounter{0}, levelZeroFile{fileName}{
    board = make_unique<Board>();
    blockFactory = make_unique<LevelZero>(fileName);
    nextBlock = blockFactory.createBlock();
}

void Player::blockIsValid(){

}

void Player::rotate(string dir){
    Block temp = nextBlock;
    if(!(nextBlock.rotate(dir) && blockIsValid())){
        nextBlock = temp;
    }
}

void Player::translate(int x, int y){
    Block temp = nextBlock;
    if(!(nextBlock.translate(x, y) && blockIsValid())){
        nextBlock = temp;
    }
}

void Player::updateFactory(){
    if(this->level = 4){
        blockFactory = make_unique<LevelFour>();
    } else if(this->level = 4){
        blockFactory = make_unique<LevelThree>();
    } else if(this->level = 4){
        blockFactory = make_unique<LevelTwo>();
    } else if(this->level = 4){
        blockFactory = make_unique<LevelOne>();
    } else{
        blockFactory = make_unique<LevelZero>(this->levelZeroFile);
    }
}

void Player::levelUp(){
    if(this->level < 4){
        this->level++;
        updateFactory();
    }
}

void Player::levelDown(){
    if(this->level > 0){
        this->level--;
        updateFactory();
    }
}
