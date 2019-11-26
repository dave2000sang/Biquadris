#include "command.h"
#include "command_type.h"
#include "blocks/j_block.h"
#include "blocks/t_block.h"
#include "blocks/block.h"
#include <iostream>
using namespace std;

int main() {
    // Command commandInterpretor;
    // string input = "66levelu";
    // int x = commandInterpretor.parseMultiplier(input);
    // CommandType cmd = commandInterpretor.parseCommand(input);
    // if (cmd == CommandType::left) {
    //     cout << "left" << ", " << x << " times" << endl;
    // } else if (cmd == CommandType::levelup) {
    //     cout << "levelup" << ", " << x << " times" << endl;
    // } else if (cmd == CommandType::leveldown) {
    //     cout << "leveldown" << ", " << x << " times" << endl;
    // } else if (cmd == CommandType::nomatch) {
    //     cout << "no match"<< endl;
    // }

    // Block *jBlock = new JBlock(0, 0, 0);
    TBlock tBlock{0,3,0};
    cout << tBlock << endl;
    tBlock.rotate("ccw");
    cout << tBlock <<endl;
    tBlock.rotate("ccw");
    cout << tBlock <<endl;
    tBlock.rotate("ccw");
    cout << tBlock <<endl;
    tBlock.rotate("ccw");
    cout << tBlock <<endl;
}
/*
 01234567890
0        J
1        JJJ
2J       
3JJJ     
4
5
6
7
8
9
10
11
12
13
14
15
16
17
*/
