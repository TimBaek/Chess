#include "pawn.h"
using namespace std;

Pawn::Pawn(Board *bd, int r, int c, string co, bool b, bool b2):
  Piece{bd, r, c, co, b}, EnPassant{b2} {
}

Pawn::~Pawn() { }

char Pawn::getLetter() {
	return (colour == "white"? 'P' : 'p');
}

bool Pawn::canEnPassant() const {
	return EnPassant;
}

void Pawn::setEnPassant(bool b) {
	EnPassant = b;
}