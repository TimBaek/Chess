#ifndef _PIECE_H
#define _PIECE_H
#include <memory>
#include "textdisplay.h"
#include "graphicdisplay.h"
#include "player.h"


class Board; //{
//public:
//  void notify(int cr, int cc, int dr, int dc);
//};
/*
class TextDisplay {
public:
  void notify(int r, int c, int rr, int cc, char ch);
};

class GraphicDisplay {
public:
  void notify(int r, int c, int rr, int cc, char ch);
};
class Player;
*/
class Piece {
 protected:
  std::shared_ptr<Board> b_obs;
  std::shared_ptr<TextDisplay> td_obs;
  std::shared_ptr<GraphicDisplay> gd_obs;
  std::shared_ptr<Player> player;
  int row;
  int col;
  char letter;

 public:
  Piece(std::shared_ptr<Board> b, std::shared_ptr<TextDisplay> td, 
    std::shared_ptr<GraphicDisplay> gd, std::shared_ptr<Player> p, int c, int r, char l);
  virtual ~Piece();
  void notifyBoard(int dr, int dc);
  void notifyTextDisplay(int dr, int dc);
  void notifyGraphicDisplay(int dr, int dc);
  virtual void move(int row, int col)=0;
  int getRow() const;
  int getCol() const;
  char getLetter() const;
};

class King: public Piece {
  bool moved = false;

 public:
  King(bool b=false);
  ~King();
  void move(int row, int col);
  bool everMoved();
};

class Queen: public Piece {
 public:
  Queen();
  ~Queen();
  void move(int row, int col);
};

class Rook: public Piece {
  bool moved = false;

 public:
  Rook(bool b=false);
  ~Rook();
  void move(int row, int col);
  bool everMoved();
};

class Knight: public Piece {
 public:
  Knight();
  ~Knight();
  void move(int row, int col);
};

class Bishop: public Piece {
 public:
  Bishop();
  ~Bishop();
  void move(int row, int col);
};

class Pawn: public Piece {
 public:
  Pawn();
  ~Pawn();
  void move(int row, int col);
};

#endif
