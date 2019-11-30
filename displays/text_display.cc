#include "text_display.h"
using namespace std;

TextDisplay::TextDisplay() : pd1{make_unique<PlayerDisplay>())}, pd2{make_unique<PlayerDisplay>()} {}

void TextDisplay::print() {
    string space = "       ";
    string border = "-----------";

    // level and score
    cout << "Level: " << setw(4) << level_1 << space << "Level: " << setw(4) << level_2 << endl;
    cout << "Score: " << setw(4) << score_1 << space << "Score: " << setw(4) << score_2 << endl;
    cout << border << space << border << endl;

    // boards
    for (int i = 0; i < height; ++i) {

        // ith row of b1
        for (int j = 0; j < width; ++j) {
            cout << theDisplay1[i][j];
        }

        // space
        cout << space;

        // ith row of b2
        for (int j = 0; j < width; ++j) {
            cout << theDisplay2[i][j];
        }
        cout << endl;
    }

    // TODO: next block
    cout << "Next:      " << space << "Next:      " << endl;
}

void TextDisplay::update(Info info) {
    if (info.player == 1) {
        theDisplay1[info.row][info.col] = info.type;
        level_1 = info.level;
        score_1 = info.score;
    } else if (info.player == 2) {
        theDisplay2[info.row][info.col] = info.type;
        level_2 = info.level;
        score_2 = info.score;
    } else {
        cout << "Error: TextDisplay::notify player is not 1 or 2" << endl;
    }
    this->print();
}
