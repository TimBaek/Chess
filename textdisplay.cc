#include <iostream>
#include "textdisplay.h"
#include "board.h"
using namespace std;

TextDisplay::TextDisplay() {

    for(int i=0; i<8; i++) {
        theDisplay.push_back(vector<char>(8));
        /*for(int j=0; j<8; j++) {
            //theDisplay[i][j] = (i+j)%2 == 0 ? '_' : ' ';
        }*/
    }
    /*
    for(int i=0; i<8; i++) {
        theDisplay.push_back(vector<char>(8));
        if(i<2 || i>5) continue;
        for(int j=0; j<8; j++) {
            theDisplay[i][j] = (i+j)%2 == 0 ? '_' : ' ';
        }
    }
    for(int j=0; j<8; j++){
        theDisplay[1][j] = 'P';
        theDisplay[6][j] = 'p';
    }
    //rooks
    theDisplay[0][0] = theDisplay[0][7] = 'R';
    theDisplay[7][0] = theDisplay[7][7] = 'r';
    //knights
    theDisplay[0][1] = theDisplay[0][6] = 'N';
    theDisplay[7][1] = theDisplay[7][6] = 'n';
    //bishops
    theDisplay[0][2] = theDisplay[0][5] = 'B';
    theDisplay[7][2] = theDisplay[7][5] = 'b';
    //queens
    theDisplay[0][3] = 'Q';
    theDisplay[7][3] = 'q';
    //kings
    theDisplay[0][4] = 'K';
    theDisplay[7][4] = 'k';
    */
}

void TextDisplay::notify(Board *b) {
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(b->isEmpty(i,j)){ theDisplay[i][j] = (i+j)%2 == 0 ? '_' : ' '; }
            else{ theDisplay[i][j] = b->getLetter(i,j); }
        }
    }
    //theDisplay[dr][dc] = theDisplay[ir][ic];
    //theDisplay[ir][ic] = (ir+ic)%2 == 0 ? '_' : ' ';
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