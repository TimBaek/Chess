#include "piece.h"
#include "board.h"
using namespace std;

// Piece 
Piece::Piece(Board *bd, int r, int c, string co):
  board{bd}, row{r}, col{c}, colour{co} {
}

Piece::~Piece() { }


void Piece::notifyBoard(int dr, int dc) {
  int tempRow = row;
  int tempCol = col;
  board->notify(tempRow, tempCol, *this);
}

int Piece::getRow() const {
  return row;
}

int Piece::getCol() const {
  return col;
}

string Piece::getColour() const {
  return colour;
}

