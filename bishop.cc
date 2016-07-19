#include "piece.h"
#include "bishop.h"
using namespace std;

Bishop::Bishop(Board *bd, int r, int c, string co, bool b):
  Piece{bd, r, c, co, b} {
}

Bishop::~Bishop() { }

char Bishop::getLetter() {
  if (colour == "white") {
    return 'B';
  } else {
    return 'b';
  }
}
