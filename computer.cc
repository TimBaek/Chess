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
cerr << "nextMove called" << endl;
	if(level==1) randomMove();
if(level==1) cerr << "level is 1" << endl;
}

void Computer::randomMove(){
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	int index=0;
	for(int r=0; r<8; r++){
		for(int c=0; c<8; c++){
			if(b->isEmpty(r,c)) continue;
			if(b->checkState(r,c)->getColour() != getColour()) continue;
			//char letter = b->checkState(r,c)->getLetter();
			//letter = letter < 'Z' ? letter + 'a' - 'A' : letter;
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
if(!(v1.size()==v2.size()==v3.size()==v4.size())) cerr << "***********" << endl;
	srand (time(NULL));
	int x = rand() % v1.size();
	currR = v1[x];
	currC = v2[x];
	destR = v3[x];
	destC = v4[x];
}
