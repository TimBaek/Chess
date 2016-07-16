#include "piece.h"
#include "board.h"
#include "controller.h"
#include <memory>
using namespace std;

// Piece 
Piece::Piece(shared_ptr<Board> bd, shared_ptr<Player> p, 
             shared_ptr<Controller> ctrl, int r, int c, char l):
  board{bd}, player{p}, ctrler{ctrl}, row{r}, col{c}, letter{l} {
}

Piece::~Piece() { }

void Piece::notifyBoard(int dr, int dc) {
  board->notify(getRow(), getCol(), dr, dc);
}

void Piece::notifyController(int dr, int dc, char l) {
// not yet
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

// King
King::King(shared_ptr<Board> bd, shared_ptr<Player> p, 
           shared_ptr<Controller> ctrl, int r, int c, char l, bool b):
  Piece{bd, p, ctrl, r, c, l}, moved{b} {
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
Queen::Queen(shared_ptr<Board> bd, shared_ptr<Player> p, 
             shared_ptr<Controller> ctrl, int r, int c, char l):
  Piece{bd, p, ctrl, r, c, l} {
}

Queen::~Queen() { }

void Queen::move(int row, int col) {
// not finished
}


// Rook
Rook::Rook(shared_ptr<Board> bd, shared_ptr<Player> p, 
           shared_ptr<Controller> ctrl, int c, int r, char l, bool b):
  Piece{bd, p, ctrl, r, c, l}, moved{b} {
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
Knight::Knight(shared_ptr<Board> bd, shared_ptr<Player> p, 
               shared_ptr<Controller> ctrl, int c, int r, char l):
  Piece{bd, p, ctrl, r, c, l} {
}

Knight::~Knight() { }

void Knight::move(int row, int col) {
// not finished
}

// Bishop 
Bishop::Bishop(shared_ptr<Board> bd, shared_ptr<Player> p, 
               shared_ptr<Controller> ctrl, int c, int r, char l):
  Piece{bd, p, ctrl, r, c, l} {
}

Bishop::~Bishop() { }

void Bishop::move(int row, int col) {
// not finished
}

// Pawn
Pawn::Pawn(shared_ptr<Board> bd, shared_ptr<Player> p, 
           shared_ptr<Controller> ctrl, int c, int r, char l, bool b):
  Piece{bd, p, ctrl, r, c, l} moved{b} {
}

Pawn::~Pawn() { }

void Pawn::move(int row, int col) {
// not finished
}

bool Pawn::everMoved() {
  return moved;
}


