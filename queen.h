#ifndef _QUEEN_H_
#define _QUEEN_H_
#include "piece.h"

class Queen: public Piece {
 public:
  Queen(Board *bd, int r, int c, std::string co);
  ~Queen();
  void move(int dr, int dc) override;
  char getLetter() override;
};

#endif
