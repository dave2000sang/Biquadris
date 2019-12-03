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
    textWidth = 100;
    textOffset = 60;
    boardWidth = width * unit;
    space = 100;
    boardHeight = height * unit;
    nextBlockWidth = 4 * unit;

    if (!isActive) return;
    xwindow = make_unique<Xwindow>(boardWidth * 2 + space, boardHeight + 3 * textWidth + nextBlockWidth);
}

int GraphicsDisplay::getColour(char type, bool hidden) {
    if (hidden) {
        return 0;
    } else if (type == '.' || type == ' ') {
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

vector<vector<bool>> GraphicsDisplay::blockToBool(Block b) {
    vector<vector<bool>> grid(4);
    int w = b.getW();
    int h = b.getH();
    vector<vector<bool>> cells = b.getCells();

    // initialize grid to 4x4 false
    for (auto &row : grid) {
        for (int i = 0; i < 4; i++) {
            row.emplace_back(false);
        }
    }

    for (int row = 0; row < h; ++row) {
        for (int col = 0; col < w; col++) {
            if (cells[row][col]) {
                grid[row][col] = true;
            } 
        }
    }

    return grid;
}

void GraphicsDisplay::printNNBs() {
    vector<vector<bool>> grid1 = this->blockToBool(NNB1);
    vector<vector<bool>> grid2 = this->blockToBool(NNB2);
    int c1 = getColour(NNB1.getType(), false);
    int c2 = getColour(NNB2.getType(), false);
    for (int row = 0; row < 4; ++row) {
        
        for (int col = 0; col < 4; ++col) {
            if (grid1[row][col]) {
                xwindow->fillRectangle(col * unit, row * unit + 3 * textWidth + boardHeight, unit, unit, c1);
            } else {
                xwindow->fillRectangle(col * unit, row * unit + 3 * textWidth + boardHeight, unit, unit, 1);
            }
        }

        for (int col = 0; col < 4; ++col) {
            if (grid2[row][col]) {
                xwindow->fillRectangle(col * unit + boardWidth + space, row * unit + 3 * textWidth + boardHeight, unit, unit, c2);
            } else {
                xwindow->fillRectangle(col * unit + boardWidth + space, row * unit + 3 * textWidth + boardHeight, unit, unit, 1);
            }
        }

    }
}

void GraphicsDisplay::printGraphics() {
    if (!isActive) return;

    // level and score
    xwindow->fillRectangle(0, 0, boardWidth, textWidth * 2, 0);
    xwindow->fillRectangle(boardWidth + space, 0, boardWidth, textWidth * 2, 0);
    xwindow->drawBigString(textOffset, textOffset, "Level: " + to_string(level_1), 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset, "Level: " + to_string(level_2), 1);
    xwindow->drawBigString(textOffset, textOffset + textWidth, "Score: " + to_string(score_1), 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset + textWidth, "Score: " + to_string(score_2), 1);

    // ith row
    xwindow->fillRectangle(0, textWidth * 2, boardWidth, boardHeight, 1);
    xwindow->fillRectangle(boardWidth + space, textWidth * 2, boardWidth, boardHeight, 1);
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (theDisplay1[i][j] == ' ' || theDisplay1[i][j] == '.') continue;
            xwindow->fillRectangle(j * unit, i * unit + 2 * textWidth, unit, unit, getColour(theDisplay1[i][j], false));
        }
        for (int j = 0; j < 11; ++j) {
            if (theDisplay2[i][j] == ' ' || theDisplay2[i][j] == '.') continue;
            xwindow->fillRectangle(boardWidth + space + j * unit, i * unit + 2 * textWidth, unit, unit, getColour(theDisplay2[i][j], false));
        }
    }

    // next next block
    xwindow->drawBigString(textOffset, textOffset + boardHeight + 2 * textWidth, "Next block: ", 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset + boardHeight + 2 * textWidth, "Next block: ", 1);
    this->printNNBs();
}


void GraphicsDisplay::graphicsPrintLevelScore() {
    if (!isActive) return;
    xwindow->fillRectangle(0, 0, boardWidth, textWidth * 2, 0);
    xwindow->fillRectangle(boardWidth + space, 0, boardWidth, textWidth * 2, 0);
    xwindow->drawBigString(textOffset, textOffset, "Level: " + to_string(level_1), 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset, "Level: " + to_string(level_2), 1);
    xwindow->drawBigString(textOffset, textOffset + textWidth, "Score: " + to_string(score_1), 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset + textWidth, "Score: " + to_string(score_2), 1);
}
void GraphicsDisplay::graphicsPrintCell(int player, int row, int col, char type, bool hidden) {
    int j = col;
    if (!isActive) return;
    int i = row;
    if (player == 1) {
        xwindow->fillRectangle(j * unit, i * unit + 2 * textWidth, unit, unit, getColour(type, hidden));
    } else {
        xwindow->fillRectangle(boardWidth + space + j * unit, i * unit + 2 * textWidth, unit, unit, getColour(type, hidden));
    }
}
void GraphicsDisplay::graphicsPrintNextBlock() {
    if (!isActive) return;
    xwindow->drawBigString(textOffset, textOffset + boardHeight + 2 * textWidth, "Next block: ", 1);
    xwindow->drawBigString(textOffset + boardWidth + space, textOffset + boardHeight + 2 * textWidth, "Next block: ", 1);
    this->printNNBs();
}

void GraphicsDisplay::update(Info info) {
    if (!isActive) return;
    if (info.player == 1) {
        theDisplay1[info.row][info.col] = info.type == ' ' ? '.' : info.type;
        level_1 = info.level;
        score_1 = info.score;
        NNB1 = info.NNB;
        this->graphicsPrintLevelScore();
        this->graphicsPrintCell(1, info.row, info.col, info.type, info.hidden);
        this->graphicsPrintNextBlock();
    } else if (info.player == 2) {
        theDisplay2[info.row][info.col] = info.type== ' ' ? '.' : info.type;
        level_2 = info.level;
        score_2 = info.score;
        NNB2 = info.NNB;
        this->graphicsPrintLevelScore();
        this->graphicsPrintCell(2, info.row, info.col, info.type, info.hidden);
        this->graphicsPrintNextBlock();
    } else {
        cout << "Error: GraphicsDisplay::notify player is not 1 or 2" << endl;
    }
}
