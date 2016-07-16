#include "piece.h"
#include "board.h"
#include <memory>
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
  td_obs->notify(getRow(), getCol(), dr, dc, getLetter());
}

void Piece::notifyGraphicDisplay(int dr, int dc) {
  gd_obs->notify(getRow(), getCol(), dr, dc, getLetter());
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
King::King(shared_ptr<Board> bd, shared_ptr<TextDisplay> td,
    shared_ptr<GraphicDisplay> gd, shared_ptr<Player> p, int c, int r, char l, bool b):
  Piece{bd, td, gd, p, r, c, l}, moved{b} {
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
Queen::Queen(shared_ptr<Board> b, shared_ptr<TextDisplay> td,
    shared_ptr<GraphicDisplay> gd, shared_ptr<Player> p, int c, int r, char l):
  Piece{b, td, gd, p, r, c, l} {
}

Queen::~Queen() { }

void Queen::move(int row, int col) {
// not finished
}


// Rook
Rook::Rook(shared_ptr<Board> bd, shared_ptr<TextDisplay> td,
    shared_ptr<GraphicDisplay> gd, shared_ptr<Player> p, int c, int r, char l, bool b):
  Piece{bd, td, gd, p, r, c, l}, moved{b} {
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
Knight::Knight(shared_ptr<Board> b, shared_ptr<TextDisplay> td,
    shared_ptr<GraphicDisplay> gd, shared_ptr<Player> p, int c, int r, char l):
  Piece{b, td, gd, p, r, c, l} {
}

Knight::~Knight() { }

void Knight::move(int row, int col) {
// not finished
}

// Bishop 
Bishop::Bishop(shared_ptr<Board> b, shared_ptr<TextDisplay> td,
    shared_ptr<GraphicDisplay> gd, shared_ptr<Player> p, int c, int r, char l):
  Piece{b, td, gd, p, r, c, l} {
}

Bishop::~Bishop() { }

void Bishop::move(int row, int col) {
// not finished
}

// Pawn
Pawn::Pawn(shared_ptr<Board> b, shared_ptr<TextDisplay> td,
    shared_ptr<GraphicDisplay> gd, shared_ptr<Player> p, int c, int r, char l):
  Piece{b, td, gd, p, r, c, l} {
}

Pawn::~Pawn() { }

void Pawn::move(int row, int col) {
// not finished
}

