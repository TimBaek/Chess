#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include "piece.h"

class Knight: public Piece {
 public:
  Knight(Board *bd, int r, int c, std::string co, bool b=false);
  ~Knight();
  char getLetter() override;
};


#endif
