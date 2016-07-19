#ifndef _PAWN_H_
#define _PAWN_H_
#include "piece.h"

class Pawn: public Piece {
  bool moved = false;

 public:
  Pawn(Board *bd, int r, int c, std::string co, bool b=false);
  ~Pawn();
  char getLetter() override;
};


#endif
