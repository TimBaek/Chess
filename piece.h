#ifndef _PIECE_H
#define _PIECE_H
#include <memory>
#include "textdisplay.h"
#include "graphicdisplay.h"
#include "player.h"

class Controller;
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
  std::shared_ptr<Board> board;
  std::shared_ptr<Player> player;
  std::shared_ptr<Controller> ctrler;
  int row;
  int col;
  char letter;

 public:
  Piece(std::shared_ptr<Board> bd, 
        std::shared_ptr<Player> p,
        std::shared_ptr<Controller> ctrl, 
	int r, int c, char l);
  virtual ~Piece();
  void notifyBoard(int dr, int dc);
  void notifyController(int dr, int dc);
  virtual void move(int row, int col)=0;
  int getRow() const;
  int getCol() const;
  char getLetter() const;
};

class King: public Piece {
  bool moved = false;

 public:
  King(std::shared_ptr<Board> bd, 
       std::shared_ptr<Player> p,
       std::shared_ptr<Controller> ctrl,
       int r, int c, char l, bool b=false);
  ~King();
  void move(int row, int col) override;
  bool everMoved();
};

class Queen: public Piece {
 public:
  Queen(std::shared_ptr<Board> bd, 
        std::shared_ptr<Player> p,
        std::shared_ptr<Controller> ctrl,
        int r, int c, char l);
  ~Queen();
  void move(int row, int col) override;
};

class Rook: public Piece {
  bool moved = false;

 public:
  Rook(std::shared_ptr<Board> bd, 
       std::shared_ptr<Player> p, 
       std::shared_ptr<Controller> ctrl,
       int r, int c, char l, bool b=false);
  ~Rook();
  void move(int row, int col) override;
  bool everMoved();
};

class Knight: public Piece {
 public:
  Knight(std::shared_ptr<Board> bd, 
         std::shared_ptr<Player> p, 
	 std::shared_ptr<Controller> ctrl,
	 int r, int c, char l);
  ~Knight();
  void move(int row, int col) override;
};

class Bishop: public Piece {
 public:
  Bishop(std::shared_ptr<Board> bd, 
         std::shared_ptr<Player> p, 
	 std::shared_ptr<Controller> ctrl,
	 int r, int c, char l);
  ~Bishop();
  void move(int row, int col) override;
};

class Pawn: public Piece {
  bool moved = false;
 public:
  Pawn(std::shared_ptr<Board> bd, 
       std::shared_ptr<Player> p, 
       std::shared_ptr<Controller> ctrl,
       int r, int c, char l, bool b=false);
  ~Pawn();
  void move(int row, int col) override;
  bool everMoved();
};

#endif
