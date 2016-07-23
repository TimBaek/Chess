#include "king.h"
using namespace std;

King::King(Board *bd, int r, int c, string co, bool b):
  Piece{bd, r, c, co, b} {
}

King::~King() { }

char King::getLetter() {
	return (colour == "white"? 'K' : 'k');
}
