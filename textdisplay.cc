#include <iostream>
#include "textdisplay.h"
#include "board.h"
using namespace std;

TextDisplay::TextDisplay() {
    for(int i=0; i<8; i++) {
        theDisplay.push_back(vector<char>(8));
}

void TextDisplay::notify(Board *b) {
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(b->isEmpty(i,j)){ theDisplay[i][j] = (i+j)%2 == 0 ? '_' : ' '; }
            else{ theDisplay[i][j] = b->getLetter(i,j); }
        }
    }
}
// dtor
TextDisplay::~TextDisplay() {}

void TextDisplay::print() {
    for(int r=7; r >= 0; r--) {
        cout << r+1 << " ";
        for(int c=0; c < 8; c++) {
            cout << theDisplay[r][c];
        }
        cout << endl;
    }
    cout << endl;
    cout << "  abcdefgh" << endl;
}