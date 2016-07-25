#include <iostream>
#include <memory>
#include <sstream>
#include "graphicdisplay.h"
#include "board.h"
using namespace std;

GraphicDisplay::GraphicDisplay(shared_ptr<Xwindow> xw): xw{xw}, origin{50}, dimension{50}, theDisplay(8,vector<char>(8)) {
}


void GraphicDisplay::notify(Board *b) {
        for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(b->isEmpty(i,j)){ theDisplay[i][j] = ' '; }
            else{ theDisplay[i][j] = b->getLetter(i,j); }
        }
    }
}

// dtor
GraphicDisplay::~GraphicDisplay() {}

void GraphicDisplay::print() {
        // print messages
        xw->drawString(200, 17, "Welcome to Chess!");
        xw->drawString(200, 34, "Black Player");
        xw->drawString(200, 487, "White Player");
        for(int i=0; i<8; i++){
        stringstream ss1, ss2;
            string message1, message2;
            int x = 80 + i * 50;
            int y = 73 + i * 50;
            ss1 << 8 - i;
            message1 = ss1.str();
            char c = 'a' + i;
            ss2 << c;
            ss2 >> message2;
            xw->drawString(23, x, message1);
            xw->drawString(y,467, message2);
        }
        // draw the board
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                int row = i*dimension + origin;
                int col = j*dimension + origin;
                if((i+j)%2 == 1) xw->fillRectangle(row, col, dimension, dimension, Xwindow::Peru);
                else xw->fillRectangle(row, col, dimension, dimension, Xwindow::Wheat);
            }
        }
        // draw the pieces
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(theDisplay[i][j] == ' ')  continue;

                int y = (7-i)*dimension + origin + 30;
                int x = j*dimension + origin + 23;
                stringstream s;
                s << theDisplay[i][j];
                string message;
                s >> message;
                xw->drawString(x,y,message);

                int linew = 3;
                int linel = 20;
                int horizx = x-10;
                int verty = y-13;
                if(theDisplay[i][j] <'Z') {
                        xw->fillRectangle(horizx, y-15,linel+4,linew,Xwindow::White);
                        xw->fillRectangle(horizx, y+4,linel+4,linew,Xwindow::White);
                        xw->fillRectangle(x-10, verty,linew,linel, Xwindow::White);
                        xw->fillRectangle(x+11, verty,linew,linel, Xwindow::White);
                }
                else{
                        xw->fillRectangle(horizx, y-15,linel+4,linew,Xwindow::Brown);
                        xw->fillRectangle(horizx, y+4,linel+4,linew,Xwindow::Brown);
                        xw->fillRectangle(x-10, verty,linew,linel, Xwindow::Brown);
                        xw->fillRectangle(x+11, verty,linew,linel, Xwindow::Brown);
                }

            }
        }
}
