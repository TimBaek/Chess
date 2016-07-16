#include "piece.h"
#include "controller.h"
#include <memory>
using namespace std;

// Piece 
Piece::Piece(shared_ptr<Controller> ctrl, int r, int c, char l, string co):
  ctrler{ctrl}, row{r}, col{c}, letter{l} colour{co} {
}

Piece::~Piece() { }


void Piece::notifyController(int dr, int dc) {
  ctrler->notify(*this, dr, dc);
}

int Piece::getRow() const {
  return row;
}

int Piece::getCol() const {
  return col;
}

char Piece::getLetter() const {
  return letter;
}

string Piece::getColour() const {
  return colour;
}

// King
King::King(shared_ptr<Controller> ctrl, int r, int c, char l, string co, bool b):
  Piece{ctrl, r, c, l, co}, moved{b} {
}

King::~King() { }

void King::move(int row, int col) {
// not finished
  moved = true;
}

bool King::everMoved() {
  return moved;
}

// Queen
Queen::Queen(shared_ptr<Controller> ctrl, int r, int c, char l, string co):
  Piece{ctrl, r, c, l, co} {
}

Queen::~Queen() { }

void Queen::move(int row, int col) {
// not finished
}


// Rook
Rook::Rook(shared_ptr<Controller> ctrl, int c, int r, char l, string co, bool b):
  Piece{ctrl, r, c, l, co}, moved{b} {
}

Rook::~Rook() { }

void Rook::move(int row, int col) {
// not finished
  moved = true;
}

bool Rook::everMoved() {
  return moved;
}

// Knight
Knight::Knight(shared_ptr<Controller> ctrl, int c, int r, char l, string co):
  Piece{ctrl, r, c, l, co} {
}

Knight::~Knight() { }

void Knight::move(int row, int col) {
// not finished
}

// Bishop 
Bishop::Bishop(shared_ptr<Controller> ctrl, int c, int r, char l, string co):
  Piece{ctrl, r, c, l, co} {
}

Bishop::~Bishop() { }

void Bishop::move(int row, int col) {
// not finished
}

// Pawn
Pawn::Pawn(shared_ptr<Controller> ctrl, int c, int r, char l, string co):
  Piece{ctrl, r, c, l, co} {
}

Pawn::~Pawn() { }

void Pawn::move(int row, int col) {

}

bool Pawn::everMoved() {
  return moved;
}


