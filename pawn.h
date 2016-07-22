#ifndef _PAWN_H_
#define _PAWN_H_
#include "piece.h"

class Pawn: public Piece {
  bool moved = false;
  bool EnPassant = false;
 public:
  Pawn(Board *bd, int r, int c, std::string co, bool b=false);
  ~Pawn();
  char getLetter() override;
  bool canEnPassant() const;
  void setEnpassant(bool b);
};


#endif
