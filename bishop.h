#ifndef _BISHOP_H_
#define _BISHOP_H_
#include "piece.h"

class Bishop: public Piece {
 public:
  Bishop(std::shared_ptr<Board> bd, int r, int c, std::string co);
  ~Bishop();
  void move(int dr, int dc) override;
  char getLetter() override;
};

#endif