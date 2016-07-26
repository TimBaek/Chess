#include "piece.h"
#include "board.h"
using namespace std;

// Piece 
Piece::Piece(Board *bd, int r, int c, string co, bool b):
  board{bd}, row{r}, col{c}, colour{co}, moved{b} {
}

Piece::~Piece() { }

void Piece::move(int dr, int dc) {
  notifyBoard(dr, dc);
  moved = true;
}

bool Piece::everMoved() const {
  return moved;
}

void Piece::notifyBoard(int dr, int dc) {
  int tempRow = row;
  int tempCol = col;
  row = dr;
  col = dc;
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

