#ifndef _KING_H_
#define _KING_H_
#include "piece.h"

class King: public Piece {
  bool moved = false;

 public:
  King(std::shared_ptr<Board> bd, int r, int c, std::string co, bool b=false);
  ~King();
  void move(int dr, int dc) override;
  bool everMoved();
  char getLetter() override;
};

#endif