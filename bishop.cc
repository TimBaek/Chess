#include "bishop.h"
using namespace std;

Bishop::Bishop(Board *bd, int r, int c, string co, bool b):
  Piece{bd, r, c, co, b} {
}

Bishop::~Bishop() { }

char Bishop::getLetter() {
	return (colour == "white"? 'B' : 'b');
}
