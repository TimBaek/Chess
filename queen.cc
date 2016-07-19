#include "piece.h"
#include "queen.h"
using namespace std;

Queen::Queen(Board *bd, int r, int c, string co, bool b):
  Piece{bd, r, c, co, b} {
}

Queen::~Queen() { }


char Queen::getLetter() {
  if (colour == "white") {
   return 'Q';
  } else {
   return 'q';
  }
}
