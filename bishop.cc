#include "piece.h"
#include "bishop.h"

Bishop::Bishop(shared_ptr<Board> bd, int c, int r, string co):
  Piece{bd, r, c, co} {
}

Bishop::~Bishop() { }

void Bishop::move(int dr, int dc) {
  notifyBoard(dr, dc);
  row = dr;
  col = dc;
}

char Bishop::getLetter() {
  if (colour == "white") {
    return 'B';
  } else {
    return 'b';
  }
}
