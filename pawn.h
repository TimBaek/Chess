#ifndef _PAWN_H_
#define _PAWN_H_
#include "piece.h"

class Pawn: public Piece {
  bool moved = false;

 public:
  Pawn(Board *bd, int r, int c, std::string co, bool b=false);
  ~Pawn();
  void move(int dr, int dc) override;
  char getLetter() override;
  bool everMoved();
};


#endif
