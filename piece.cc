#include "piece.h"
using namespace std;

// Piece 
Piece::Piece(shared_ptr<Board> b, shared_ptr<TextDisplay> td, shared_ptr<GraphicDisplay> gd,
             shared_ptr<Player> p, int c, int r, char l):
  b_obs{b}, td_obs{td}, gd_obs{gd}, player{p}, col{c}, row{r}, letter{l} {
}

Piece::~Piece() { }

void Piece::notifyBoard(int dr, int dc) {
  b_obs->notify(getRow(), getCol(), dr, dc);
}

void Piece::notifyTextDisplay(int dr, int dc) {
  td_obs->notify(getRow(), getCol(), dr, dc);
}

void Piece::notifyGraphicDisplay(int dr, int dc) {
  gd_obs->notify(getRow(), getCol(), dr, dc);
}

int Piece::getRow() {
  return row;
}

int Piece::getCol() {
  return col;
}

char Piece::getLetter() {
  return letter;
}

// King
King::King(bool b):
  Piece{b_obs, td_obs, gd_obs, player, row, col, letter}, moved{b} {
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
Queen::Queen():
  Piece{b_obs, td_obs, gd_obs, player, row, col, letter} {
}

Queen::~Queen() { }

void Queen::move(int row, int col) {
// not finished
}


// Rook
Rook::Rook(bool b):
  Piece{b_obs, td_obs, gd_obs, player, row, col, letter}, moved{b} {
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
Knight::Knight():
  Piece{b_obs, td_obs, gd_obs, player, row, col, letter} {
}

Knight::~Knight() { }

void Knight::move(int row, int col) {
// not finished
}

// Bishop 
Bishop::Bishop():
  Piece{b_obs, td_obs, gd_obs, player, row, col, letter} {
}

Bishop::~Bishop() { }

void Bishop::move(int row, int col) {
// not finished
}

// Pawn
Pawn::Pawn():
  Piece{b_obs, td_obs, gd_obs, player, row, col, letter} {
}

Pawn::~Pawn() { }

void Pawn::move(int row, int col) {
// not finished
}


