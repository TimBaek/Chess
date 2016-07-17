#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include "piece.h"

class Knight: public Piece {
 public:
  Knight(std::shared_ptr<Board> bd, int r, int c, std::string co);
  ~Knight();
  void move(int dr, int dc) override;
  char getLetter() override;
};


#endif