#include "piece.h"
#include "rook.h"

Rook::Rook(shared_ptr<Board> bd, int c, int r, string co, bool b):
  Piece{bd, r, c, co}, moved{b} {
}

Rook::~Rook() { }

void Rook::move(int dr, int dc) {
  notifyBoard(dr, dc);
  row = dr;
  col = dc;
  moved = true;
}

bool Rook::everMoved() {
  return moved;
}

char Rook::getLetter() {
  if (colour == "white") {
    return 'R';
  } else {
    return 'r';
  }
}
