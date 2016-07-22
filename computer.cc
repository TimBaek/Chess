#include "computer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
using namespace std;

Computer::Computer(string colour, int level, Board *b): colour{colour}, stalemate{false}, checkmate{false}, check{false}, b{b}, level{level}, currR{-1}, currC{-1}, destR{-1}, destC{-1} {}

Computer::~Computer() {}

struct Coordinates{
	int row,col;
};

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
	else if(level==3){ capturingMove(); }
}

void Computer::randomMove(){
	vector<Coordinates> coord1,coord2;
	for(int r=0; r<8; r++){
		for(int c=0; c<8; c++){
			if(b->isEmpty(r,c)) continue;
			if(b->checkState(r,c)->getColour() != getColour()) continue;
			for(int i=0; i<8; i++){
				for(int j=0; j<8; j++){
char ch1 = 'a' + c;
char ch2 = 'a' + j;
cout << "try moving: " << ch1 << r+1 << " to " << ch2 << i+1 <<  endl;
					if(!b->canMove(b->checkState(r,c), i, j, getColour())) continue;
					coord1.push_back(Coordinates{r,c});
					coord2.push_back(Coordinates{i,j});
				}
			}
		}
	}
	srand (time(NULL));
	int x = rand() % coord1.size();
	currR = coord1[x].row;
	currC = coord1[x].col;
	destR = coord2[x].row;
	destC = coord2[x].col;
char c1 = 'a' + currC;
char c2 = 'a' + destC;	
cout << "moved: " << c1 << currR+1 << " to " << c2 << destR+1 <<  endl;
}

void Computer::avoidCapture(){
	// priority of pieces to avoid captures for:
	// pawn < knight < rook < bishop < queen < king
	// each corresponds to 1-6 according to the priority
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
					char letter = b->checkState(i,j)->getLetter();
					letter = letter < 'Z' ? letter + 'a' - 'A' : letter;
					int priority;
					switch(letter) {
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


void Computer::capturingMove(){
	
	string oppColour = getColour()=="black" ? "white" : "black";
	int currPriority=0;
	for(int r=0; r<8; r++){
		for(int c=0; c<8; c++){
			if(b->isEmpty(r,c)) continue;
			if(b->checkState(r,c)->getColour() != getColour()) continue;
			for(int i=0; i<8; i++){
				for(int j=0; j<8; j++){
					if(b->checkState(i,j) == nullptr) continue;
					if(!b->canMove(b->checkState(r,c), i, j, getColour())) continue;
					if(b->checkState(i,j)->getColour() != oppColour) continue;
					char letter = b->checkState(i,j)->getLetter();
					letter = letter < 'Z' ? letter + 'a' - 'A' : letter;
					int priority;
					switch(letter) {
						case 'k': priority = 6; break;
						case 'q': priority = 5; break;
						case 'b': priority = 4; break;
						case 'r': priority = 3; break;
						case 'n': priority = 2; break;
						case 'p': priority = 1;
					}
					if(priority<= currPriority) continue;
					currPriority = priority;
					currR = r;
					currC = c;
					destR = i;
					destC = j;
				}
			}
		}
	}
	// if there is no possible capture, avoid being captured.
	if(currPriority==0) avoidCapture();
	char c1 = 'a' + currC;
	char c2 = 'a' + destC;
cout << "moved: " << c1 << currR+1 << " to " << c2 << destR+1 <<  endl;
}



/*
void Computer::avoidCapture2(){
	// priority of pieces to avoid captures for:
	// pawn < knight < rook < bishop < queen < king
	// each is stored in v[1-6] according to the priority

	vector<Coordinates> v1,v2,v3,v4,v5,v6;

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
//cout << "found a piece that's capturable: " << i << j << endl;
					char c = b->checkState(i,j)->getLetter();
					c = c < 'Z' ? c + 'a' - 'A' : c;
					switch(c) {
						case 'k': v6.push_back(Coordinates{i,j}); break;
						case 'q': v5.push_back(Coordinates{i,j}); break;
						case 'b': v4.push_back(Coordinates{i,j}); break;
						case 'r': v3.push_back(Coordinates{i,j}); break;
						case 'n': v2.push_back(Coordinates{i,j}); break;
						case 'p': v1.push_back(Coordinates{i,j});
					}
				}
			}
		}
	}
	vector<vector<Coordinates>> possibleCapture{v1,v2,v3,v4,v5,v6};
	bool decidedWhich = false;
	for(int i=5; i>=0; i--){
		int j = possibleCapture[i].size();
		while(j>0){
			//v6[j].row = i
			//v6[j].col = j
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
*/

