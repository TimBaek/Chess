#ifndef _ROOK_H_
#define _ROOK_H_
#include "piece.h"

class Rook: public Piece {
 public:
  Rook(Board *bd, int r, int c, std::string co, bool b=false);
  ~Rook();
  char getLetter() override;
};


#endif
