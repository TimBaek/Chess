#ifndef _PIECE_H_
#define _PIECE_H_
#include <memory>
#include <string>

class Board;
/*
class Piece;
class Board {
 public:
  void notify(int r, int c, Piece &p) {
  }
};
*/


class Piece {
 protected:
  Board *board;
  int row;
  int col;
  std::string colour;

 public:
  Piece(Board *bd, int r, int c, std::string co);
  virtual ~Piece();
  void notifyBoard(int dr, int dc);
  virtual void move(int dr, int dc)=0;
  int getRow() const;
  int getCol() const;
  virtual char getLetter()=0;
  std::string getColour() const;
};


#endif
