#ifndef _KING_H_
#define _KING_H_
#include "piece.h"

class King: public Piece {
 public:
  King(Board *bd, int r, int c, std::string co, bool b=false);
  ~King();
  char getLetter() override;
};

#endif
