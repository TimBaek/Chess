#include "computer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
using namespace std;

Computer::Computer(string colour, int level, Board *b): colour{colour}, stalemate{false}, checkmate{false}, check{false}, b{b}, level{level}, currR{-1}, currC{-1}, destR{-1}, destC{-1} {}

Computer::~Computer() {}

string Computer::getColour() { return colour; }
string Computer::getName(){ return "computer"; }

bool Computer::isStalemate() { return stalemate; }

bool Computer::isCheckmate() { return checkmate; }

bool Computer::isCheck() { return check; }

void Computer::setBoard(Board *board){ b = board; }

int Computer::getR(){ return currR; }
int Computer::getC(){ return currC; }
int Computer::getDestR(){ return destR; }
int Computer::getDestC(){ return destC; }

void Computer::nextMove(){
cout << "nextMove called with level " << level << endl;
	if(level==1) randomMove();
	else if(level==2){ avoidCapture(); }
}

void Computer::randomMove(){
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	for(int r=0; r<8; r++){
		for(int c=0; c<8; c++){
			if(b->isEmpty(r,c)) continue;
			if(b->checkState(r,c)->getColour() != getColour()) continue;
			for(int i=0; i<8; i++){
				for(int j=0; j<8; j++){
					if(!b->canMove(b->checkState(r,c), i, j, getColour())) continue;
					v1.push_back(r);
					v2.push_back(c);
					v3.push_back(i);
					v4.push_back(j);
				}
			}
		}
	}
	srand (time(NULL));
	int x = rand() % v1.size();
	currR = v1[x];
	currC = v2[x];
	destR = v3[x];
	destC = v4[x];
}

void Computer::avoidCapture(){
	// priority of pieces to avoid captures for:
	// pawn < knight < rook < bishop < queen < king
	// each corresponds to 1-6 according to the priorityy
	int r1,r2,c1,c2;
	int currPriority=0;
	string oppColour = getColour()=="black" ? "white" : "black";

	for(int r=0; r<8; r++){
		for(int c=0; c<8; c++){
			if(b->isEmpty(r,c)) continue;
			if(b->checkState(r,c)->getColour() == getColour()) continue;
			for(int i=0; i<8; i++){
				for(int j=0; j<8; j++){
					if(b->checkState(i,j) == nullptr) continue;
					if(!b->canMove(b->checkState(r,c), i, j, oppColour)) continue;
					if(b->checkState(i,j)->getColour() != getColour()) continue;
cout << "found a piece that's capturable: " << i << j << endl;
					char c = b->checkState(i,j)->getLetter();
					c = c < 'Z' ? c + 'a' - 'A' : c;
cout << "and it's the piece " << c << endl;
					int priority;
					switch(c) {
						case 'k': priority = 6; break;
						case 'q': priority = 5; break;
						case 'b': priority = 4; break;
						case 'r': priority = 3; break;
						case 'n': priority = 2; break;
						case 'p': priority = 1;
					}
					if(priority<= currPriority) continue;
					bool movable=false;
					for(int x=0; x<8; x++){
						if(movable) break;
						for(int y=0; y<8; y++){
							if(b->canMove(b->checkState(i,j),x,y, getColour())){
								r2=x;
								c2=y;
								movable = true;
								// stops the loop once it finds a move
								// which might not necessarily be the best move.
								break;
							}
						}
					}
					if(!movable) continue;
					currPriority = priority;
					r1=i;
					c1=j;
				}
			}
		}
	}
	if(currPriority==0){
		randomMove();
		return;
	}
	currR = r1;
	currC = c1;
	destR = r2;
	destC = c2;
}


