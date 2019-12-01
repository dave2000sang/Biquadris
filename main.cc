#include "game.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[]) {
    int seed = 1, startlevel = 0;
    bool graphicsActive = true;
    string file1 = "sequence1.txt", file2 = "sequence2.txt";

    for (int i = 1; i < argc; i++) {
        string cur = argv[i];
        if (cur == "-text") {
            graphicsActive = false;
        } else if (cur == "-seed") {
            if (++i < argc) {
                int seed = stoi(argv[i]);
                cout << "setting seed to " << seed << endl;
                srand(seed);
            } else {
                cout << "No seed provided" << endl;
                return -1;
            }
        } else if (cur == "-scriptfile1") {
            if (++i < argc) {
                file1 = argv[i];
            } else {
                cout << "Error reading scriptfile1" << endl;
                return -1;
            }
        } else if (cur == "-scriptfile2") {
            if (++i < argc) {
                file2 = argv[i];
            } else {
                cout << "Error reading scriptfile2" << endl;
                return -1;
            }
        } else if (cur == "-startlevel") {
            if (++i < argc) {
                startlevel = stoi(argv[i]);
            } else {
                cout << "Error reading startlevel" << endl;
                return -1;
            }
        } else {
            cout << "Error reading command line argument" << endl;
            return -1;
        }
    }
    Game game{startlevel, file1, file2, graphicsActive};
}
