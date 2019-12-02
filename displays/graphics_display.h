#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include "info.h"
#include "window.h"
#include "../blocks/block.h"

class GraphicsDisplay {

    const int width = 11;
    const int height = 18;

    std::vector<std::vector<char>> theDisplay1;
    std::vector<std::vector<char>> theDisplay2;
    int level_1, level_2, score_1, score_2;

    // graphics
    std::unique_ptr<Xwindow> xwindow;

    int unit;
    int textWidth;
    int textOffset;
    int boardWidth;
    int space;
    int boardHeight;
    int nextBlockWidth;

    Block NNB1;
    Block NNB2;

    public:
    bool isActive;
    GraphicsDisplay(bool isActive);
    void update(Info info);
    void graphicsPrintLevelScore();
    void graphicsPrintCell(int player, int row, int col, char type);
    void graphicsPrintNextBlock();
    void printGraphics(); // play and restart

    // helpers
    int getColour(char type);
    std::vector<std::vector<bool>> blockToBool(Block b); // converts block to 4x4 bools
    void printNNBs();
};
#endif
