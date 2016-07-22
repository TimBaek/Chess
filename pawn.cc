#include "piece.h"
#include "pawn.h"
using namespace std;

Pawn::Pawn(Board *bd, int r, int c, string co, bool b):
  Piece{bd, r, c, co, b} {
}

Pawn::~Pawn() { }

char Pawn::getLetter() {
  if (colour == "white") {
    return 'P';
  } else {
    return 'p';
  }
}

bool Pawn::canEnPassant() const {
	return EnPassant;
}

void Pawn::setEnPassant(bool b) {
	EnPassant = b;
}