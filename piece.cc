#include "piece.h"
#include "board.h"
#include <memory>
#include <string>
using namespace std;

// Piece 
Piece::Piece(shared_ptr<Board> bd, int r, int c, string co):
  board{bd}, row{r}, col{c}, colour{co} {
}

Piece::~Piece() { }


void Piece::notifyBoard(int dr, int dc) {
  int tempRow = row;
  int tempCol = col;
  board->notify(tempRow, tempCol, dr, dc);
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

// King
King::King(shared_ptr<Board> bd, int r, int c, string co, bool b):
  Piece{bd, r, c, co}, moved{b} {
}

King::~King() { }

void King::move(int dr, int dc) {
  notifyBoard(dr, dc);
  row = dr;
  col = dc;
  moved = true;
}

bool King::everMoved() {
  return moved;
}

char King::getLetter() {
  if (colour == "white") {
    return 'K';
  } else {
    return 'k';
  }
}

// Queen
Queen::Queen(shared_ptr<Board> bd, int r, int c, string co):
  Piece{bd, r, c, co} {
}

Queen::~Queen() { }

void Queen::move(int dr, int dc) {
  notifyBoard(dr, dc);
  row = dr;
  col = dc;
}

char Queen::getLetter() {
  if (colour == "white") {
   return 'Q';
  } else {
   return 'q';
  }
}

// Rook
Rook::Rook(shared_ptr<Board> bd, int c, int r, string co, bool b):
  Piece{bd, r, c, co}, moved{b} {
}

Rook::~Rook() { }

void Rook::move(int dr, int dc) {
  notifyBoard(dr, dc);
  row = dr;
  col = dc;
  moved = true;
}

bool Rook::everMoved() {
  return moved;
}

char Rook::getLetter() {
  if (colour == "white") {
    return 'R';
  } else {
    return 'r';
  }
}

// Knight
Knight::Knight(shared_ptr<Board> bd, int c, int r, string co):
  Piece{bd, r, c, co} {
}

Knight::~Knight() { }

void Knight::move(int dr, int dc) {
  notifyBoard(dr, dc);
  row = dr;
  col = dc;
}

char Knight::getLetter() {
  if (colour == "white") {
    return 'N';
  } else {
   return 'n';
  }
}

// Bishop 
Bishop::Bishop(shared_ptr<Board> bd, int c, int r, string co):
  Piece{bd, r, c, co} {
}

Bishop::~Bishop() { }

void Bishop::move(int dr, int dc) {
  notifyBoard(dr, dc);
  row = dr;
  col = dc;
}

char Bishop::getLetter() {
  if (colour == "white") {
    return 'B';
  } else {
    return 'b';
  }
}

// Pawn
Pawn::Pawn(shared_ptr<Board> bd, int c, int r, string co, bool b):
  Piece{bd, r, c, co}, moved{b} {
}

Pawn::~Pawn() { }

void Pawn::move(int dr, int dc) {
  notifyBoard(dr, dc);
  row = dr;
  col = dc;
  moved = true;
}

bool Pawn::everMoved() {
  return moved;
}

char Pawn::getLetter() {
  if (colour == "white") {
    return 'P';
  } else {
    return 'p';
  }
}

