#include "piece.h"
#include "queen.h"

Queen::Queen(shared_ptr<Board> bd, int r, int c, string co):
  Piece{bd, r, c, co} {
}

Queen::~Queen() { }

void Queen::move(int dr, int dc) {
  notifyBoard(dr, dc);
  row = dr;
  col = dc;
}

char Queen::getLetter() {
  if (colour == "white") {
   return 'Q';
  } else {
   return 'q';
  }
}
