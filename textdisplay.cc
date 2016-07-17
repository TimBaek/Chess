#include <iostream>
#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay() {
  for(int i=0; i<8; i++) {
        currStates.push_back(vector<char>(8));
        for(int j=0; j<8; j++) {
                currStates[i][j] = nullptr;
        }
  }
}

void TextDisplay::notify(int ir, int ic, int dr, int dc) {
}

// dtor
TextDisplay::~TextDisplay() {}

ostream &operator<<(ostream &out, const TextDisplay &td) {
        for(int c=0; c < 8; ++c) {
                for(int r=0; r < 8; ++r) {
                        out << currStates[r][c];
                }
                out << endl;
        }
        return out;
}