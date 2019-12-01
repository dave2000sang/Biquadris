#include "graphics_display.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(bool isActive): level_1{0}, level_2{0}, score_1{0}, score_2{0}, isActive{isActive} {
    for(int i = 0; i < height; ++i){
        vector<char> temp1;
        vector<char> temp2;
        for(int j = 0; j < width; ++j){
            temp1.emplace_back('.');
            temp2.emplace_back('.');
        }
        theDisplay1.emplace_back(temp1);
        theDisplay2.emplace_back(temp2);
    }

    unit = 30;
    textWidth = 30;
    textOffset = 20;
    boardWidth = width * unit;
    space = 100;
    boardHeight = height * unit;
    nextBlockWidth = 4 * unit;

    if (!isActive) return;
    xwindow = make_unique<Xwindow>(boardWidth * 2 + space, boardHeight + 3 * textWidth + nextBlockWidth);
}

int GraphicsDisplay::getColour(char type) {
    if (type == '.' || type == ' ') {
        return 1;
    } else if (type == 'I') {
        return 2;
    } else if (type == 'J') {
        return 3;
    } else if (type == 'L') {
        return 4;
    } else if (type == 'O') {
        return 5;
    } else if (type == 'S') {
        return 6;
    } else if (type == 'Z') {
        return 7;
    } else if (type == 'T') {
        return 8;
    } else if (type == '*') {
        return 9;
    } else {
        return 0; // white
    }
}

void GraphicsDisplay::printGraphics() {
    if (!isActive) return;

    // level and score
    xwindow->drawBigString(textOffset, textOffset, "Level: " + to_string(level_1), 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset, "Level: " + to_string(level_2), 1);
    xwindow->drawBigString(textOffset, textOffset + textWidth, "Score: " + to_string(score_1), 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset + textWidth, "Score: " + to_string(score_2), 1);

    // ith row
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            xwindow->fillRectangle(j * unit, i * unit + 2 * textWidth, unit, unit, getColour(theDisplay1[i][j]));
        }
        for (int j = 0; j < 11; ++j) {
            xwindow->fillRectangle(boardWidth + space + j * unit, i * unit + 2 * textWidth, unit, unit, getColour(theDisplay2[i][j]));
        }
    }

    // next block
    xwindow->drawBigString(textOffset, textOffset + boardHeight + 2 * textWidth, "Next block: ", 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset + boardHeight + 2 * textWidth, "Next block: ", 1);
}


void GraphicsDisplay::graphicsPrintLevelScore() {
    if (!isActive) return;
    xwindow->drawBigString(textOffset, textOffset, "Level: " + to_string(level_1), 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset, "Level: " + to_string(level_2), 1);
    xwindow->drawBigString(textOffset, textOffset + textWidth, "Score: " + to_string(score_1), 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset + textWidth, "Score: " + to_string(score_2), 1);
}
void GraphicsDisplay::graphicsPrintCell(int player, int row, int col, char type) {
    int j = col;
    if (!isActive) return;
    int i = row;
    if (player == 1) {
        xwindow->fillRectangle(j * unit, i * unit + 2 * textWidth, unit, unit, getColour(type));
    } else {
        xwindow->fillRectangle(boardWidth + space + j * unit, i * unit + 2 * textWidth, unit, unit, getColour(type));
    }
}
void GraphicsDisplay::graphicsPrintNextBlock() {
    if (!isActive) return;
    xwindow->drawBigString(textOffset, textOffset + boardHeight + 2 * textWidth, "Next block: ", 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset + boardHeight + 2 * textWidth, "Next block: ", 1);
}

void GraphicsDisplay::update(Info info) {
    if (!isActive) return;
    if (info.player == 1) {
        theDisplay1[info.row][info.col] = info.type == ' ' ? '.' : info.type;
        level_1 = info.level;
        score_1 = info.score;
        this->graphicsPrintLevelScore();
        this->graphicsPrintCell(1, info.row, info.col, info.type);
        this->graphicsPrintNextBlock();
    } else if (info.player == 2) {
        theDisplay2[info.row][info.col] = info.type== ' ' ? '.' : info.type;
        level_2 = info.level;
        score_2 = info.score;
        this->graphicsPrintLevelScore();
        this->graphicsPrintCell(2, info.row, info.col, info.type);
        this->graphicsPrintNextBlock();
    } else {
        cout << "Error: GraphicsDisplay::notify player is not 1 or 2" << endl;
    }
}
