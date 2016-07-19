#include "piece.h"
#include "knight.h"
using namespace std;

Knight::Knight(Board *bd, int c, int r, string co, bool b=false):
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
