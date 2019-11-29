#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "observer.h"
#include "subject.h"

class TextDisplay: public Observer {

    const int width = 11;
    const int height = 18;

    // p1
    std::vector<std::vector<char>> b1;
    int level_1;
    int score_1;
    // TODO: next block

    // p2
    std::vector<std::vector<char>> b2;
    int level_2;
    int score_2;
    // TODO: next block

    public:
    TextDisplay();
    void notify(Subject &whoNotified) override;
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
    // TODO: how to update score and level
};
#endif
