#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include "info.h"
#include "window.h"

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
};
#endif
