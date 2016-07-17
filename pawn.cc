#include "piece.h"
#include "pawn.h"

Pawn::Pawn(shared_ptr<Board> bd, int c, int r, string co, bool b):
  Piece{bd, r, c, co}, moved{b} {
}

Pawn::~Pawn() { }

void Pawn::move(int dr, int dc) {
  notifyBoard(dr, dc);
  row = dr;
  col = dc;
  moved = true;
}

bool Pawn::everMoved() {
  return moved;
}

char Pawn::getLetter() {
  if (colour == "white") {
    return 'P';
  } else {
    return 'p';
  }
}
