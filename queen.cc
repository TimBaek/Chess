#include "queen.h"
using namespace std;

Queen::Queen(Board *bd, int r, int c, string co, bool b):
  Piece{bd, r, c, co, b} {
}

Queen::~Queen() { }


char Queen::getLetter() {
	return (colour == "white"? 'Q' : 'q');
}
