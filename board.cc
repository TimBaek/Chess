#include <iostream>
#include <vector>
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

void Board::clearBoard(){

}

void Board::notify(int r, int c, Piece &p){
	updateState(r,c, (p.getRow()), (p.getCol()));
}

bool Board::isThere(Piece &p, int r, int c){
	return((p.getRow()==r) && (p.getCol()==c));
}

bool Board::canMove(Piece &p, int r, int c){
	return true;
}

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

	blackMoves.resize(numPieces("black"));
	whiteMoves.resize(numPieces("white"));
	for(int i=0; i<8; i++){
		currStates.push_back(vector<shared_ptr<Piece>>(8));
		//blackMoves[i].resize(8);
		//whiteMoves[i].resize(8);
		for(int j=0; j<8; j++){
			currStates[i][j] = nullptr;
			//blackMoves[i][j].resize(8);
			//whiteMoves[i][j].resize(8);
		}
	}
	/*
	for(int i=0; i<numPieces("black");i++){
		for(int j=0; j<8; j++){
			for(int k=0; k<8; k++){
				blackMoves[i][j][k] = 0;
			}
		}
	}
	*/
	player1 == "white" ? defaultSetup(player1, player2) : defaultSetup(player2, player1);
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
		case 'k' : currStates[r][c] = make_shared<King>(this,r,c,colour);
		case 'q' : currStates[r][c] = make_shared<King>(this,r,c,colour);
		case 'b' : currStates[r][c] = make_shared<Bishop>(this,r,c,colour);
		case 'p' : currStates[r][c] = make_shared<Pawn>(this,r,c,colour);
		case 'r' : currStates[r][c] = make_shared<Rook>(this,r,c,colour);
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

/*
TextDisplay &Board::getTd() const {
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			td->setCoord()
		}
	}
	return *td;
}

ostream &operator<<(std::ostream &out, const Board &b){
	out << b.getTd();
	return out;
}
*/

