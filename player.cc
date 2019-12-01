#include "player.h"
#include "block_factory/level_zero.h"
#include "block_factory/level_one.h"
#include "block_factory/level_two.h"
#include "block_factory/level_three.h"
#include "block_factory/level_four.h"
#include <exception>
#include <iostream>

Player::Player(string fileName): blockID{1}, score{0}, level{0}, starCounter{0}{
    levelZeroFile = fileName;
    board = make_shared<Board>();
    board->init();
    blockFactory = make_shared<LevelZero>(fileName);
    nextBlock = blockFactory->createBlock();
    nextNextBlock = blockFactory->createBlock();
    board->draw(nextBlock, blockID);
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
