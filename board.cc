#include <iostream>
#include <vector>
#include <cstdlib>
#include "board.h"
#include "human.h"
#include "computer.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
using namespace std;

Board::Board(Controller *ctrl): ctrl{ctrl}, wp{nullptr}, bp{nullptr} {}
Board::~Board() {}


void Board::notify(int r, int c, Piece &p){
	updateState(r,c, (p.getRow()), (p.getCol()));
}

bool Board::isThere(Piece &p, int r, int c){
	return((p.getRow()==r) && (p.getCol()==c));
}

void Board::updateState(int r, int c, int destr, int destc){
	shared_ptr<Piece> tmp = currStates[r][c];
	currStates[destr][destc] = tmp;
	currStates[r][c] = nullptr;
}


void Board::init(){
	// initializing Current State
	for(int i=0; i<8; i++){
		currStates.push_back(vector<shared_ptr<Piece>>(8));
		for(int j=0; j<8; j++){
			currStates[i][j] = nullptr;
		}
	}
	defaultSetup(wp->getColour(), bp->getColour());
}

void Board::setPlayers(shared_ptr<Player> w, shared_ptr<Player> b) {
	wp = w;
	bp = b;
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
			if (currStates[i][j] == nullptr) continue;
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

bool Board::isbadPawnPosition() {
	for (int c = 0; c < 8; c++) {
		if (currStates[7][c] == nullptr) continue;
		if(currStates[7][c]->getLetter() == 'p') return false;
	}
	for (int c = 0; c < 8; c++) {
		if (currStates[0][c] == nullptr) continue;
		if(currStates[0][c]->getLetter() == 'P') return false;
	}
	return true;
}

char Board::getLetter(int r, int c){
	if(currStates[r][c]==nullptr) return ' ';
	else return currStates[r][c]->getLetter();
}

bool Board::canMove(shared_ptr<Piece> p, int destr, int destc, string plcol) {
	if (p == nullptr) return false;
	char let = p->getLetter();
	if (p->getColour() != plcol) return false;
	if (p->getRow() == destr && p->getCol() == destc) return false;
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
	// regular moves
	if ((abs(destr -crow) == 1 && abs(destc -ccol) == 1) ||
		(destr == crow && (destc == ccol +1 || destc == ccol -1)) ||
		(destc == ccol && (destr == crow +1 || destr == crow -1))) {
		if (checkState(destr,destc) == nullptr ||
			checkState(destr,destc)->getColour() != colour) {
			return true;
		} else {
			return false;
		}
	// castleing move
	} else if (destr == crow && (destc == ccol +2 || destc == ccol -2)) {
		if (checkState(crow,ccol)->everMoved() == true) return false;
		// checking if the squares are empty
		int colInc = (ccol < destc? 1 : -1);
		while(0 < ccol && ccol < 7) {
			ccol += colInc; 
			if (checkState(crow,ccol) != nullptr) break;
		}
		// checking if there is an ally rook
		if (checkState(crow,ccol) != nullptr &&
			p->everMoved() == false &&
			(checkState(crow,ccol)->getLetter() == 
			(colour == "white"? 'R' : 'r'))) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool Board::canMoveQ(shared_ptr<Piece> p, int destr, int destc, string col) {
	string colour = p->getColour();
	int crow = p->getRow();
	int ccol = p->getCol();

	while(true) {
		// straight move
		if (destr == crow || destc == ccol) {
			if (destr < crow) {
				--crow;
			} else if (destr > crow) {
				++crow;
			} else if (destc < ccol) {
				--ccol;
			} else if (destc > ccol) {
				++ccol;
			}
		// diagonal move
		} else if (abs(crow -destr) == abs(ccol -destc)) {
			int rowInc = (crow < destr? 1 : -1);
			int colInc = (ccol < destc? 1 : -1);
			crow += rowInc;
			ccol += colInc;
		}
		// check if destination is empty or an enemy
		if (destr == crow && destc == ccol) {
			if (checkState(destr,destc) == nullptr ||
				checkState(destr,destc)->getColour() != colour) {
				return true;
			} else {
				return false;
			}
		// check if the way to destination is empty
		} else {
			if (checkState(crow,ccol) == nullptr) {
				continue;
			} else {
				return false;
			}
		}
		
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
			if (checkState(destr,destc) == nullptr ||
				checkState(destr,destc)->getColour() != colour) {
				return true;
			} else {
				return false;
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

	if ((destc == ccol +2 && (destr == crow +1 || destr == crow -1)) ||
	    (destc == ccol -2 && (destr == crow +1 || destr == crow -1)) ||
	    (destr == crow +2 && (destc == ccol +1 || destc == ccol -1)) ||
	    (destr == crow -2 && (destc == ccol +1 || destc == ccol -1))) {
		if (checkState(destr,destc) == nullptr ||
			checkState(destr,destc)->getColour() != colour) {
	    	return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}


bool Board::canMoveB(shared_ptr<Piece> p, int destr, int destc, string col) {
	string colour = p->getColour();
	int crow = p->getRow();
	int ccol = p->getCol();
	int rowInc = (crow < destr? 1 : -1);
	int colInc = (ccol < destc? 1 : -1);
	if (abs(crow -destr) != abs(ccol -destc)) return false;
	while(true) {
		crow += rowInc;
		ccol += colInc;
		if (crow != destr && ccol != destc) {
			if (checkState(crow,ccol) == nullptr) {
				continue;
			} else {
				return false;
			}
		} else {
			if (checkState(crow,ccol) == nullptr ||
				checkState(crow,ccol)->getColour() != colour) {
				return true;
			} else {
				return false;
			}
		}
	}
}


void Board::offEnPassant(string colour) {
	int row = (colour == "white"? 4 : 3);
	for(int i=0; i < 8; ++i) {
		auto piece = checkState(row,i);
		if (row == 4 && piece && piece->getLetter() == 'P') {
			dynamic_pointer_cast<Pawn>(piece)->setEnPassant(false);
		} else if (row == 3 && piece && piece->getLetter() == 'p') {
			dynamic_pointer_cast<Pawn>(piece)->setEnPassant(false);
		}
 	}
}

bool Board::canMoveP(shared_ptr<Piece> p, int destr, int destc, string col) {
	string colour = p->getColour();
	int crow = p->getRow();
	int ccol = p->getCol();
	char enemyPawn = (p->getLetter() == 'p'? 'P':'p'); 
	int one = (colour == "white"? 1 : -1);
	int two = (colour == "white"? 2 : -2);

	// diagonal move
	if (destr == crow +one && (destc == ccol +1 || destc == ccol -1)) {
		if ((checkState(destr,destc) == nullptr &&
			dynamic_pointer_cast<Pawn>(p)->canEnPassant()) // EnPassant move
			||
			((checkState(destr,destc) &&
			checkState(destr,destc)->getColour() != colour))) // Attacking move
			return true;
		else return false;
	// double step move
	} else if (destr == crow +two && destc == ccol) {
		if (p->everMoved() == false &&
			checkState(crow +one, ccol) == nullptr &&
			checkState(crow +two, ccol) == nullptr) {
			if (ccol -1 >= 0) {
				auto left = dynamic_pointer_cast<Pawn>(checkState(destr,ccol-1));
				if (left && left->getLetter() == enemyPawn) {
					left->setEnPassant(true);
				}
			}
			if (ccol +1 <= 7.) {
				auto right = dynamic_pointer_cast<Pawn>(checkState(destr,ccol+1));
				if (right && right->getLetter() == enemyPawn) {
					right->setEnPassant(true);
				}
			}
			return true;	
		} else {
			return false;
		}
	// regular move
	} else if (destr == crow +one && destc == ccol) {
		if (checkState(crow +one, ccol) == nullptr) return true;
		else return false;
	} else {
		return false;
	}
}


void Board::castling(int r, int c, int destc) {
	int rcol = c;
	int jumpedCol = (c < destc? c +1 : c -1);
	while(true) {
		if (c < destc) {
			++rcol;
		} else {
			--rcol;
		}
		if (checkState(r, rcol)) break;
	}
	checkState(r,rcol)->move(r,jumpedCol);
}


bool isValidRC(int r, int c) {
	return ((0 <= r && r <= 7) &&
	        (0 <= c && c <= 7));
}

bool Board::isPromo(int r, int c, int destr, int destc) {
	if (!isValidRC(r,c) || !isValidRC(destr,destc)) return false;
	auto cp = checkState(r,c);
	auto dp = checkState(destr, destc);
	if (cp && !dp && 
		((cp->getLetter() == 'p' && destr == 0) ||
		(cp->getLetter() == 'P' && destr == 7))) {
		return true;
	} else {
		return false;
	}
} 


bool Board::willBeChecked(int r, int c, int destr, int destc, string colour) {
	vector<vector<shared_ptr<Piece>>> vBoard;
	char klet = (colour == "white"? 'K':'k');
	int krow = -1;
	int kcol = -1;
	
	// setting vBoard based on currState
	for(int i=0; i < 8; ++i) {
		vBoard.emplace_back(vector<shared_ptr<Piece>>(8));
		for(int j=0; j < 8; ++j) {
			auto p = checkState(i,j);
			if (p) {
				if (p->getLetter() == klet) {
					krow = p->getRow();
					kcol = p->getCol();
				}
				if(p->getLetter() == 'K' || p->getLetter() == 'k') {
					vBoard[i][j] = make_shared<King>(this, p->getRow(), p->getCol(), p->getColour());
				} else if(p->getLetter() == 'Q' || p->getLetter() == 'q') {
					vBoard[i][j] = make_shared<Queen>(this, p->getRow(), p->getCol(), p->getColour());
				} else if(p->getLetter() == 'B' || p->getLetter() == 'b') {
					vBoard[i][j] = make_shared<Bishop>(this, p->getRow(), p->getCol(), p->getColour());
				} else if(p->getLetter() == 'R' || p->getLetter() == 'r') {
					vBoard[i][j] = make_shared<Rook>(this, p->getRow(), p->getCol(), p->getColour());
				} else if(p->getLetter() == 'N' || p->getLetter() == 'n') {
					vBoard[i][j] = make_shared<Knight>(this, p->getRow(), p->getCol(), p->getColour());
				} else if(p->getLetter() == 'P' || p->getLetter() == 'p') {
					vBoard[i][j] = make_shared<Pawn>(this, p->getRow(), p->getCol(), p->getColour());
				}	
			} else {
				vBoard[i][j] = nullptr;
			}
		}
	}
	if (isValidRC(r,c) && isValidRC(destr,destc)) {
		// castling
		if (vBoard[r][c]->getLetter() == 'k' || vBoard[r][c]->getLetter() == 'K') {
			if (destr == r && abs(destc - c) == 2) {
				int rcol = c;
				int jumpedCol = (c < destc? c +1 : c -1);
				int colInc = (c < destc? 1:-1);
				while(true) {
					rcol += colInc;
					if (vBoard[r][rcol]) break;
				}
				vBoard[r][jumpedCol] = vBoard[r][rcol];
				vBoard[r][rcol] = nullptr;
			} 
		// EnPassant		
		} else if (vBoard[r][c]->getLetter() == 'p' || vBoard[r][c]->getLetter() == 'P') {
			if (abs(destr -r) == 1 && abs(destc -c) == 1 &&	vBoard[r][c] == nullptr) {
				if (colour == "white") vBoard[destr -1][destc] = nullptr;
				else vBoard[destr +1][destc];
			} 
		}
		vBoard[destr][destc] = vBoard[r][c];
		vBoard[r][c] = nullptr;
	}
	
	if (krow == r && kcol == c) {
		krow = destr;
		kcol = destc;
	}
	char enemyPawn = (colour == "white"? 'p' : 'P');
	char enemyBishop = (colour == "white"? 'b' : 'B');
	char enemyKnight = (colour == "white"? 'n' : 'N');
	char enemyRook = (colour == "white"? 'r' : 'R');
	char enemyQueen = (colour == "white"? 'q' : 'Q');
	char enemyKing = (colour == "white"? 'k' : 'K');

	// up
	for(int i=krow+1; isValidRC(i,kcol); ++i) {
		if (getLetter(i,kcol) == enemyRook || getLetter(i,kcol) == enemyQueen) return true;
		if (vBoard[i][kcol] && vBoard[i][kcol]->getColour() == colour) break;
	}
	// down
	for(int i=krow-1; isValidRC(i,kcol); --i) {
		if (getLetter(i,kcol) == enemyRook || getLetter(i,kcol) == enemyQueen) return true;
		if (vBoard[i][kcol] && vBoard[i][kcol]->getColour() == colour) break;
	}
	// left
	for(int i=kcol-1; isValidRC(krow,i); --i) {
		if (getLetter(krow,i) == enemyRook || getLetter(krow,i) == enemyQueen) return true;
		if (vBoard[krow][i] && vBoard[krow][i]->getColour() == colour) break;
	}
	// right
	for(int i=kcol+1; isValidRC(krow,i); ++i) {
		if (getLetter(krow,i) == enemyRook || getLetter(krow,i) == enemyQueen) return true;
		if (vBoard[krow][i] && vBoard[krow][i]->getColour() == colour) break;
	}
	// up-right
	int i = krow +1;
	int j = kcol +1;
	while (isValidRC(i,j)) {
		if (getLetter(i,j) == enemyBishop || getLetter(i,j) == enemyQueen) return true;
		if (vBoard[i][j] && vBoard[i][j]->getColour() == colour) break;
		++i;
		++j;
	}
	// down-right
	i = krow -1;
	j = kcol +1;
	while (isValidRC(i,j)) {
		if (getLetter(i,j) == enemyBishop || getLetter(i,j) == enemyQueen) return true;
		if (vBoard[i][j] && vBoard[i][j]->getColour() == colour) break;		
		--i;
		++j;
	}
	// down-left
	i = krow -1;
	j = kcol -1;
	while (isValidRC(i,j)) {
		if (getLetter(i,j) == enemyBishop || getLetter(i,j) == enemyQueen) return true;
		if (vBoard[i][j] && vBoard[i][j]->getColour() == colour) break;		
		--i;
		--j;
	}
	// up-left
	i = krow +1;
	j = kcol -1;
	while (isValidRC(i,j)) {
		if (getLetter(i,j) == enemyBishop || getLetter(i,j) == enemyQueen) return true;
		if (vBoard[i][j] && vBoard[i][j]->getColour() == colour) break;
		++i;
		--j;
	}
	int ePawnRow = (colour == "white"? krow +1: krow -1);

	// left pawn check
	if ((isValidRC(ePawnRow, kcol -1) && getLetter(ePawnRow,kcol -1) == enemyPawn)) return true;
	// right pawn check
	if ((isValidRC(ePawnRow, kcol +1) && getLetter(ePawnRow,kcol +1) == enemyPawn)) return true;

	// king vs king check
	if (isValidRC(krow, kcol +1) && getLetter(krow, kcol +1) == enemyKing) 		 return true;
	if (isValidRC(krow +1, kcol +1) && getLetter(krow +1, kcol +1) == enemyKing) return true;
	if (isValidRC(krow +1, kcol) && getLetter(krow +1, kcol) == enemyKing) 		 return true;
	if (isValidRC(krow +1, kcol -1) && getLetter(krow +1, kcol -1) == enemyKing) return true;
	if (isValidRC(krow, kcol -1) && getLetter(krow, kcol -1) == enemyKing) 		 return true;
	if (isValidRC(krow -1, kcol -1) && getLetter(krow -1, kcol -1) == enemyKing) return true;
	if (isValidRC(krow -1, kcol) && getLetter(krow -1, kcol) == enemyKing) 		 return true;
	if (isValidRC(krow -1, kcol +1) && getLetter(krow -1, kcol +1) == enemyKing) return true;

	// knight
	if ((isValidRC(krow+1, kcol+2) && getLetter(krow+1, kcol+2) == enemyKnight) ||
		(isValidRC(krow-1, kcol+2) && getLetter(krow-1, kcol+2) == enemyKnight) ||
		(isValidRC(krow+2, kcol+1) && getLetter(krow+2, kcol+1) == enemyKnight) ||
		(isValidRC(krow-2, kcol+1) && getLetter(krow-2, kcol+1) == enemyKnight) ||
		(isValidRC(krow+2, kcol-1) && getLetter(krow+2, kcol-1) == enemyKnight) ||
		(isValidRC(krow+1, kcol-2) && getLetter(krow+1, kcol-2) == enemyKnight) ||
		(isValidRC(krow-1, kcol-2) && getLetter(krow-1, kcol-2) == enemyKnight) ||
		(isValidRC(krow-2, kcol-1) && getLetter(krow-2, kcol-1) == enemyKnight)) {
		return true;
	}
	return false;
}

bool Board::isCheckmate(string colour) {
	vector<shared_ptr<Piece>> pieces;
	// collecting the same colour pieces and finding king
	for(int r=0; r < 8; ++r) {
		for(int c=0; c < 8; ++c) {
			auto piece = checkState(r,c);
			if (piece) {
				if (piece->getColour() == colour) {
					pieces.emplace_back(piece);
				}
			}
		}
	}

	// check if there is a legal move that stops check
	int len = pieces.size();
	for(int i=0; i < len; ++i) {
		for (int r=0; r < 8; ++r) {
			for(int c=0; c < 8; ++c) {
				auto p = pieces.at(i);
				if (canMove(p, r, c, colour) &&
					!willBeChecked(p->getRow(), p->getCol(), r,c, colour)) {
					return false;
				}
			}
		}
	}
	return true;
}

bool Board::isStalemate(string colour) {
	vector<shared_ptr<Piece>> pieces;
	// collecting the same colour pieces and finding king
	for(int r=0; r < 8; ++r) {
		for(int c=0; c < 8; ++c) {
			auto piece = checkState(r,c);
			if (piece) {
				if (piece->getColour() == colour) {
					pieces.emplace_back(piece);
				}
			}
		}
	}

	// check if there is a legal move
	int len = pieces.size();
	for(int i=0; i < len; ++i) {
		for (int r=0; r < 8; ++r) {
			for(int c=0; c < 8; ++c) {
				auto p = pieces.at(i);
				if (canMove(p, r, c, colour)) {
					return false;
				}
			}
		}
	}
	return true;	
}