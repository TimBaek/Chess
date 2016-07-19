#include <iostream>
#include <vector>
#include <cstdlib>
#include "board.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
using namespace std;

Board::Board(Controller *ctrl): ctrl{ctrl}, player1{""}, player2{""} {}
Board::~Board() {}


void Board::notify(int r, int c, Piece &p){
	updateState(r,c, (p.getRow()), (p.getCol()));
}

bool Board::isThere(Piece &p, int r, int c){
	return((p.getRow()==r) && (p.getCol()==c));
}

/*
bool Board::canMove(int r, int c, int destr, int destc){
	return true;
}
*/
void Board::updateState(int r, int c, int destr, int destc){
	shared_ptr<Piece> tmp = currStates[r][c];
	currStates[destr][destc] = tmp;
	currStates[r][c] = nullptr;
	updatePossibleMove();
}

void Board::updatePossibleMove(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(currStates[i][j]==nullptr) continue;
			updatePiece(currStates[i][j]);
		}
	}
}

void Board::updatePiece(shared_ptr<Piece> p){

}


void Board::init(string p1, string p2){
	player1 = p1;
	player2 = p2;

	// initializing Current State
	for(int i=0; i<8; i++){
		currStates.push_back(vector<shared_ptr<Piece>>(8));
		blackMoves.push_back(vector<vector<int>>(8));
		for(int j=0; j<8; j++){
			currStates[i][j] = nullptr;
		}
	}

	player1 == "white" ? defaultSetup(player1, player2) : defaultSetup(player2, player1);

	// initializing Possible Moves
	cerr << "blackMoves initialization" << endl;
	cerr << "numBlack is " << numPieces("black") << endl;
	for(int i=0; i<numPieces("black"); i++){
		blackMoves.push_back(vector<vector<int>>());
		whiteMoves.push_back(vector<vector<int>>());
		for(int j=0; j<8; j++){
			blackMoves[i].push_back(vector<int>());
			whiteMoves[i].push_back(vector<int>());
			for(int k=0; k<8; k++){
				blackMoves[i][j].push_back(0);
				whiteMoves[i][j].push_back(0);
			}
		}
	}

}



// Default setup:
// colour1 is for the white player
// colour2 is for the black player
void Board::defaultSetup(string colour1, string colour2){
	//shared_ptr<Board> b = make_shared<Board>(*this);
	//pawns
	for (int i=0; i<8; i++){
		currStates[1][i] = make_shared<Pawn>(this,1,i,colour1);
		currStates[6][i] = make_shared<Pawn>(this,6,i,colour2);
	}
	//rooks
	for (int i=0; i<8; i+=7){
		currStates[0][i] = make_shared<Rook>(this,0,i,colour1);
		currStates[7][i] = make_shared<Rook>(this,7,i,colour2);
	}
	//knights
	for (int i=1; i<8; i+=5){
		currStates[0][i] = make_shared<Knight>(this,0,i,colour1);
		currStates[7][i] = make_shared<Knight>(this,7,i,colour2);
	}
	//bishops
	for (int i=2; i<8; i+=3){
		currStates[0][i] = make_shared<Bishop>(this,0,i,colour1);
		currStates[7][i] = make_shared<Bishop>(this,7,i,colour2);
	}
	//kings and queens
	currStates[0][4] = make_shared<King>(this,0,4,colour1);
	currStates[7][4] = make_shared<King>(this,7,4,colour2);
	currStates[0][3] = make_shared<Queen>(this,0,3,colour1);
	currStates[7][3] = make_shared<Queen>(this,7,3,colour2);
}




void Board::setup(){
	for(int i=0; i<8; i++){
		currStates.push_back(vector<shared_ptr<Piece>>(8));
		for(int j=0; j<8; j++){ currStates[i][j] = nullptr; }
	}
}

void Board::setup_add(char letter, int r, int c){
	setup_delete(r,c);
	char tmp = (letter < 'Z') ? letter+'a'-'A' : letter;
	string colour = (letter < 'Z') ? "white" : "black";
	switch (tmp){
		case 'k' : currStates[r][c] = make_shared<King>(this,r,c,colour); break;
		case 'q' : currStates[r][c] = make_shared<Queen>(this,r,c,colour); break;
		case 'b' : currStates[r][c] = make_shared<Bishop>(this,r,c,colour); break;
		case 'p' : currStates[r][c] = make_shared<Pawn>(this,r,c,colour); break;
		case 'r' : currStates[r][c] = make_shared<Rook>(this,r,c,colour); break;
		case 'n' : currStates[r][c] = make_shared<Knight>(this,r,c,colour);
	}
}

void Board::setup_delete(int r, int c){
	if(currStates[r][c]==nullptr) return;
	currStates[r][c] = nullptr;
}

int Board::numKing(string colour){
	int num=0;
	char k = colour== "black" ? 'k' : 'K';
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if((currStates[i][j]->getColour()==colour)&&
				(currStates[i][j]->getLetter() == k))
				num++;
		}
	}
	return num;

}

int Board::numPieces(string colour){
	int num=0;
	if(currStates.size()==0) return 0;
	for (int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(currStates[i][j]==nullptr) continue;
			if(currStates[i][j]->getColour()==colour) num++;
		}
	}
	return num;
}


shared_ptr<Piece> Board::checkState(int r, int c){
	return currStates[r][c];
}

bool Board::isEmpty(int r, int c){
	return currStates[r][c]==nullptr;

}

char Board::getLetter(int r, int c){
	if(currStates[r][c]==nullptr) return ' ';
	else return currStates[r][c]->getLetter();
}

bool Board::canMove(shared_ptr<Piece> p, int destr, int destc, string plcol) {
	if (p == nullptr) return false;
	char let = p->getLetter();
	if (p->getColour() != plcol) return false;
	if (let == 'k' || let == 'K') {
		return canMoveK(p, destr, destc, plcol);
	} else if (let == 'q' || let == 'Q') {
		return canMoveQ(p, destr, destc, plcol);
	} else if (let == 'r' || let == 'R') {
		return canMoveR(p, destr, destc, plcol);
	} else if (let == 'n' || let == 'N') {
		return canMoveN(p, destr, destc, plcol);
	} else if (let == 'b' || let == 'B') {
		return canMoveB(p, destr, destc, plcol);
	} else {
		return canMoveP(p, destr, destc, plcol);
	}
}

bool Board::canMoveK(shared_ptr<Piece> p, int destr, int destc, string col) {
	string colour = p->getColour();
	int crow = p->getRow();
	int ccol = p->getCol();

	if ((abs(destr -crow) == 1 && abs(destc -ccol) == 1) ||
		(destr == crow && (destc == ccol +1 || destc == ccol -1)) ||
		(destc == ccol && (destr == crow +1 || destc == crow -1))) {
		if (checkState(destr,destc) == nullptr ||
			checkState(destr,destc)->getColour() != colour) {
			return true;
		} else {
			return false;
		}
	} else if (destr == crow && (destc == ccol +2 || destc == ccol -2)) {
		while(1 <= ccol || ccol <= 8) {
			if (destc > ccol) {
				++ccol;
			} else {
				--ccol;
			} 
			if (!checkState(crow,ccol)) break;
		}
		if ((checkState(crow,ccol)->getLetter() == 
			(colour == "white"? 'R' : 'r')) &&
			checkState(crow,ccol)->everMoved() == false) {
			return true;
		} 
	} else {
		return false;
	}
}

bool Board::canMoveQ(shared_ptr<Piece> p, int destr, int destc, string col) {
	string colour = p->getColour();
	int crow = p->getRow();
	int ccol = p->getCol();

	if (destr == crow || destc != ccol) {
		while (true) {
			if (destr < crow) {
				--crow;
			} else if (destr > crow) {
				++crow;
			} else if (destc < ccol) {
				--ccol;
			} else if (destc > ccol) {
				++ccol;
			}
			if (destr == crow && destc == ccol) {
				if (checkState(crow,ccol)->getColour() == colour) {
					return false;
				} else {
					return true;
				}
			} else {
				if (checkState(crow,ccol) == nullptr) {
					continue;
				} else {
					return false;
				}
			}
		}	
	} else if (abs(crow -destr) != abs(ccol -destc)) {
		while(true) {
			if (crow < destr && ccol < destc) {
				++crow;
				++ccol;
			} else if (crow < destr && ccol > destc) {
				++crow;
				--ccol;
			} else if (crow > destr && ccol < destc) {
				--crow;
				++ccol;
			} else {
				--crow;
				--ccol;
			}
			if (crow != destr && ccol != destc) {
				if (checkState(crow,ccol) == nullptr) {
					continue;
				} else {
					return false;
				}
			} else {
				if (checkState(crow,ccol)->getColour() == colour) {
					return false;
				} else {
					return true;
				}
			}
		}	
	} else {
		 return false;
	}

}

bool Board::canMoveR(shared_ptr<Piece> p, int destr, int destc, string col) {
	string colour = p->getColour();
	int crow = p->getRow();
	int ccol = p->getCol();

	if (destr != crow && destc != ccol) return false;
	while (true) {
		if (destr < crow) {
			--crow;
		} else if (destr > crow) {
			++crow;
		} else if (destc < ccol) {
			--ccol;
		} else if (destc > ccol) {
			++ccol;
		}
		if (destr == crow && destc == ccol) {
			if (checkState(crow,ccol)->getColour() == colour) {
				return false;
			} else {
				return true;
			}
		} else {
			if (checkState(crow,ccol) == nullptr) {
				continue;
			} else {
				return false;
			}
		}
	}
}


bool Board::canMoveN(shared_ptr<Piece> p, int destr, int destc, string col) {
	string colour = p->getColour();
	int crow = p->getRow();
	int ccol = p->getCol();

	if ((destc == ccol +2 && destr == crow +1) ||
	    (destc == ccol +2 && destr == crow -1) ||
	    (destc == ccol -2 && destr == crow +1) ||
	    (destc == ccol -2 && destr == crow -1) ||
	    (destr == crow +2 && destc == ccol +1) ||
	    (destr == crow +2 && destc == ccol -1) ||
	    (destr == crow -2 && destc == ccol +1) ||
	    (destr == crow -2 && destc == ccol -1)) {
		if (checkState(destr,destc) == nullptr ||
			checkState(destr,destc)->getColour() != colour) {
	    	return true;
		}
	} else {
		return false;
	}
}


bool Board::canMoveB(shared_ptr<Piece> p, int destr, int destc, string col) {
	string colour = p->getColour();
	int crow = p->getRow();
	int ccol = p->getCol();

	if (abs(crow -destr) != abs(ccol -destc)) return false;
	while(true) {
		if (crow < destr && ccol < destc) {
			++crow;
			++ccol;
		} else if (crow < destr && ccol > destc) {
			++crow;
			--ccol;
		} else if (crow > destr && ccol < destc) {
			--crow;
			++ccol;
		} else {
			--crow;
			--ccol;
		}
		if (crow != destr && ccol != destc) {
			if (checkState(crow,ccol) == nullptr) {
				continue;
			} else {
				return false;
			}
		} else {
			if (checkState(crow,ccol)->getColour() == colour) {
				return false;
			} else {
				return true;
			}
		}
	}
}

bool Board::canMoveP(shared_ptr<Piece> p, int destr, int destc, string col) {
	string colour = p->getColour();
	int crow = p->getRow();
	int ccol = p->getCol();

	// attack move
	if (destr == crow +1 && (destc == ccol +1 || destc == ccol -1)) {
		if (checkState(destr,destc)->getColour() != colour) return true;
	// double step move
	} else if (destr == crow +2 && destc == ccol) {
		if (p->everMoved() == false &&
			checkState(crow +1, ccol) == nullptr &&
			checkState(crow +2, ccol) == nullptr) {
			return true;
		}
	// regular move
	} else if (ldestr == crow +1 && destc == ccol) {
		if (checkState(crow +1, ccol) == nullptr) return true;
	} else {
		return false;
	}
}

/*
bool Board::isChecked(int r, int c, int destr, int destc) {
	vector<vector<shared_ptr<Piece>>> virtBoard;
	for(int r=0; r < 8; ++r) {
		virtBoard.emplace_back(vector<shared_ptr<Piece>>{});
		for(int c=0; c < 8; ++c) {

		}
	}
}
*/
