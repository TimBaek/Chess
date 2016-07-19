#include "piece.h"
#include "rook.h"
using namespace std;

Rook::Rook(Board *bd, int c, int r, string co, bool b):
  Piece{bd, r, c, co, b} {
}

Rook::~Rook() { }

char Rook::getLetter() {
  if (colour == "white") {
    return 'R';
  } else {
    return 'r';
  }
}
