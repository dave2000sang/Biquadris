#include "text_display.h"
using namespace std;

TextDisplay::TextDisplay(): level_1{0}, level_2{0}, score_1{0}, score_2{0}{
    for(int i = 0; i < height; ++i){
        vector<char> temp1;
        vector<char> temp2;
        for(int j = 0; j < width; ++j){
            temp1.emplace_back(' ');
            temp2.emplace_back(' ');
        }
        theDisplay1.emplace_back(temp1);
        theDisplay2.emplace_back(temp2);
    }
}

vector<vector<bool>> TextDisplay::blockToBool(Block b) {
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

void TextDisplay::printNNBs() {
    
    string space = "";
    for (int n = 0; n < 14; ++n) {
        space+=" ";
    }

    vector<vector<bool>> grid1 = this->blockToBool(this->NNB1);
    vector<vector<bool>> grid2 = this->blockToBool(NNB2);
    char type1 = NNB1.getType();
    char type2 = NNB2.getType();

    for (int row = 0; row < 4; ++row) {

        for (int col = 0; col < 4; ++col) {
            if (grid1[row][col]) {
                cout << type1;
            } else {
                cout << ' ';
            }
        }

        cout << space;

        for (int col = 0; col < 4; ++col) {
            if (grid2[row][col]) {
                cout << type2;
            } else {
                cout << ' ';
            }
        }

        cout << endl;

    }
}

void TextDisplay::print() {

    string space = "";
    for (int n = 0; n < 7; ++n) {
        space+=" ";
    }
    string border = "";
    for (int n = 0; n < 11; ++n) {
        border+="-";
    }

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

    cout << border << space << border << endl;
    cout << "Next:      " << space << "Next:      " << endl;
    this->printNNBs();
    // cout << NNB1 << endl;
    // cout << NNB2 << endl;
}



void TextDisplay::update(Info info) {
    if (info.player == 1) {
        if(!info.hidden){
            theDisplay1[info.row][info.col] = info.type == ' ' ? ' ' : info.type;
        } else{
            theDisplay1[info.row][info.col] = '?';
        }
        level_1 = info.level;
        score_1 = info.score;
        NNB1 = info.NNB;
    } else if (info.player == 2) {
        if(!info.hidden){
            theDisplay2[info.row][info.col] = info.type == ' ' ? ' ' : info.type;
        } else{
            theDisplay2[info.row][info.col] = '?';
        }
        level_2 = info.level;
        score_2 = info.score;
        NNB2 = info.NNB;
    } else {
        cout << "Error: TextDisplay::notify player is not 1 or 2" << endl;
    }
}
