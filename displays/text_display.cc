#include "text_display.h"
using namespace std;

TextDisplay::TextDisplay() {
    
    // initializing player 1's board
    b1 = vector<vector<char>> (height);
    for (auto &row : b1) {
        for (int i = 0; i < width; ++i) {
            row.emplace_back(' ');
        }
    }

    // initializing player 2's board
    b2 = vector<vector<char>> (height);
    for (auto &row : b2) {
        for (int i = 0; i < width; ++i) {
            row.emplace_back(' ');
        }
    }

    // level and score for both players start at 0
    level_1 = 0;
    level_2 = 0;
    score_1 = 0;
    score_2 = 0;
}

void TextDisplay::notify(Subject &whoNotified) {
    // TODO: make cell a child of subject and implement notify
    // TODO: add a info class for subject that contains the type and position of cell
    
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    // TODO
    string space = "       ";
    string border = "-----------";

    // level and score
    out << "Level: " << setw(4) << td.level_1 << space << "Level: " << setw(4) << td.level_2 << endl;
    out << "Score: " << setw(4) << td.score_1 << space << "Score: " << setw(4) << td.score_2 << endl;
    out << border << space << border << endl;

    // boards
    for (int i = 0; i < td.height; ++i) {

        // ith row of b1
        for (int j = 0; j < td.width; ++j) {
            out << td.b1[i][j];
        }

        // space
        out << space;

        // ith row of b2
        for (int j = 0; j < td.width; ++j) {
            out << td.b2[i][j];
        }
        out << endl;
    }

    // next block
    out << "Next:      " << space << "Next:      " << endl;
    // TODO: next block

    return out;
}
