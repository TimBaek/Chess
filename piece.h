#ifndef _PIECE_H_
#define _PIECE_H_
#include <string>

class Board;

class Piece {
 protected:
  Board *board;
  int row;
  int col;
  std::string colour;
  bool moved;

 public:
  Piece(Board *bd, int r, int c, std::string co, bool b=false);
  virtual ~Piece();
  void notifyBoard(int dr, int dc);
  void move(int dr, int dc);
  bool everMoved() const;
  int getRow() const;
  int getCol() const;
  virtual char getLetter()=0;
  std::string getColour() const;
};


#endif
