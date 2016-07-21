#include "computer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
using namespace std;

Computer::Computer(string colour, int level): colour{colour}, stalemate{false}, checkmate{false}, check{false}, b{nullptr}, level{level} {}

Computer::~Computer() {}

string Computer::getColour() { return colour; }
string Computer::getName(){ return "computer"; }

bool Computer::isStalemate() { return stalemate; }

bool Computer::isCheckmate() { return checkmate; }

bool Computer::isCheck() { return check; }

void Computer::setBoard(Board *board){ b = board; }

string Computer::nextMove(){
	if(level==1) return randomMove();
}

string Computer::randomMove(){
	std::vector<string> v;
	int index=0;
	for(int r=0; r<8; r++){
		for(int c=0; c<8; c++){
			if(b->isEmpty(r,c)) continue;
			if(b->checkState(r,c)->getColour() != getColour()) continue;
			char letter = b->checkState(r,c)->getLetter();
			letter = letter < 'Z' ? letter + 'a' - 'A' : letter;
			for(int i=0; i<8; i++){
				for(int j=0; j<8; j++){
					if(!b->canMove(b->checkState(r,c), i, j, getColour())) continue;
					stringstream ss;
					ss << r << c << i << j;
					string s = ss.str();
					v.push_back(s);
				}
			}
		}
	}
	srand (time(NULL));
	int x = rand() % v.size();
	return v[x];
}
