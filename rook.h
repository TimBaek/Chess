#ifndef _ROOK_H_
#define _ROOK_H_
#include "piece.h"

class Rook: public Piece {
  bool moved = false;

 public:
  Rook(std::shared_ptr<Board> bd, int r, int c, std::string co, bool b=false);
  ~Rook();
  void move(int dr, int dc) override;
  bool everMoved();
  char getLetter() override;
};


#endif