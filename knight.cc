#include "piece.h"
#include "knight.h"
using namespace std;

Knight::Knight(Board *bd, int r, int c, string co, bool b):
  Piece{bd, r, c, co, b} {
}

Knight::~Knight() { }

char Knight::getLetter() {
  if (colour == "white") {
    return 'N';
  } else {
   return 'n';
  }
}
