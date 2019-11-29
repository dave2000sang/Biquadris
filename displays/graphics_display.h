#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "observer.h"
#include "window.h"
#include "subject.h"
#include <iostream>

class Xwindow;

class GraphicsDisplay : public Observer {

    Xwindow *xwindow = nullptr;
    const int width = 11;
    const int height = 18;

    // p1
    int level_1;
    int score_1;
    // TODO: next block

    // p2
    int level_2;
    int score_2;
    // TODO: next block

    public:
    GraphicsDisplay(int w = 11, int h = 18);
    ~GraphicsDisplay();
    void notify(Subject &whoNotified) override;
    void printWinner(int player);
    // TODO: how to update level and score
};

#endif
