#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include "info.h"

class TextDisplay {

    const int width = 11;
    const int height = 18;

    std::vector<std::vector<char>> theDisplay1;
    std::vector<std::vector<char>> theDisplay2;
    int level_1, level_2, score_1, score_2;

    public:
    TextDisplay();
    void update(Info info);
    void print(); // textdisplay
};
#endif
