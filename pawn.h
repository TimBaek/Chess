#ifndef _PAWN_H_
#define _PAWN_H_
#include "piece.h"

class Pawn: public Piece {
  bool EnPassant = false;
 public:
  Pawn(Board *bd, int r, int c, std::string co, bool b=false, bool b2=false);
  ~Pawn();
  char getLetter() override;
  bool canEnPassant() const;
  void setEnPassant(bool b);
};


#endif
