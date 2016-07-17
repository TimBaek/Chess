#include "piece.h"
#include "king.h"

King::King(shared_ptr<Board> bd, int r, int c, string co, bool b):
  Piece{bd, r, c, co}, moved{b} {
}

King::~King() { }

void King::move(int dr, int dc) {
  notifyBoard(dr, dc);
  row = dr;
  col = dc;
  moved = true;
}

bool King::everMoved() {
  return moved;
}

char King::getLetter() {
  if (colour == "white") {
    return 'K';
  } else {
    return 'k';
  }
}
