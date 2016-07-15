#include <iostream>
#include <vector>
#include "board.h"
using namespace std;

Board::Board(TextDisplay *td, GraphicDisplay *gd): td{td}, gd{gd} {}
Board::~Board() { 
	delete td;
	delete gd;
}

void Board::clearBoard(){ 

}

void notify(int r, int c, int destr, int destc){

}

bool isThere(Piece &p, int r, int c){
	return((p->getRow()==r) && (p->getCol()==c));
}

bool canMove(Piece &p, int r, int c);

void updateState();


void init(Player *player1, Player *player2){
	//if(!td) td = 
	for(int i=0; i<8; i++){
		currStates.push_back(vector<Piece>(8));
		for(int j=0; j<8; j++){
			currStates[i][j] = (i+j)%2 ==0 ? ' ' : '_';
		}
	}
	makePieces(player1, player2);	

}

void defaultSetup(Player *player1, Player *player2){
	//pawns
	for (int i=0; i<8; i++){
		Pawn p1{this, player1, td, gd, 1, i, 'p'};
		Pawn p2{this, player2, td, gd, 6, i, 'P'};
		P1.push_back(p1);
		P2.push_back(p2);
		currStates[1][i] = 'p';
		currStates[6][i] = 'P';
	}
	//rooks
	for (int i=0; i<8; i+=7){
		Rook r1{this, player1, td, gd, 0, i, 'r'};
		Rook r2{this, player2, td, gd, 7, i, 'R'};
		P1.push_back(r1);
		P2.push_back(r2);
		currStates[0][i] = 'r';
		currStates[7][i] = 'R';
	}
	//knights
	for (int i=1; i<8; i+=5){
		Knight k1{this, player1, td, gd, 0, i, 'n'};
		Knight k2{this, player2, td, gd, 7, i, 'N'};
		P1.push_back(k1);
		P2.push_back(k2);
		currStates[0][i] = 'n';
		currStates[7][i] = 'N';
	}
	//bishops
	for (int i=2; i<8; i+=3){
		Bishop b1{this, player1, td, gd, 0, i, 'b'};
		Bishop b2{this, player2, td, gd, 7, i, 'B'};
		P1.push_back(b1);
		P2.push_back(b2);
		currStates[0][i] = 'b';
		currStates[7][i] = 'B';
	}
	//kings and queens
	King k1{this, player1, td, gd, 0, 4, 'k'};
	King k2{this, player2, td, gd, 7, 4, 'K'};
	Queen q1{this, player1, td, gd, 0, 3, 'q'};
	Queen q2{this, player2, td, gd, 7, 3, 'Q'};
	P1.push_back(k1);
	P1.push_back(q1);
	P2.push_back(k2);
	P2.push_back(q2);
	currStates[0][4] = 'k';
	currStates[7][4] = 'K';
	currStates[0][3] = 'q';
	currStates[7][3] = 'Q';
}



void setup();

friend ostream &operator<<(std::ostream &out, const Board &b);

