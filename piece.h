#ifndef _PIECE_H
#define _PIECE_H
#include <memory>
#include <string>

class Controller;

class Piece {
 protected:
  std::shared_ptr<Controller> ctrler;
  int row;
  int col;
  char letter;
  std::string colour;

 public:
  Piece(std::shared_ptr<Controller> ctrl, 
        int r, int c, char l, std::string co);
  virtual ~Piece();
  void notifyController(int dr, int dc);
  virtual void move(int row, int col)=0;
  int getRow() const;
  int getCol() const;
  char getLetter() const;
  std::string getColour() const;
};

class King: public Piece {
  bool moved = false;

 public:
  King(std::shared_ptr<Controller> ctrl, 
       int r, int c, char l, std::string co, bool b=false);
  ~King();
  void move(int row, int col) override;
  bool everMoved();
};

class Queen: public Piece {
 public:
  Queen(std::shared_ptr<Controller> ctrl,
        int r, int c, char l, string co);
  ~Queen();
  void move(int row, int col) override;
};

class Rook: public Piece {
  bool moved = false;

 public:
  Rook(std::shared_ptr<Controller> ctrl,
       int r, int c, char l, std::string co, bool b=false);
  ~Rook();
  void move(int row, int col) override;
  bool everMoved();
};

class Knight: public Piece {
 public:
  Knight(std::shared_ptr<Controller> ctrl,
	 int r, int c, char l, std::string co);
  ~Knight();
  void move(int row, int col) override;
};

class Bishop: public Piece {
 public:
  Bishop(std::shared_ptr<Controller> ctrl,
	 int r, int c, char l, std::string co);
  ~Bishop();
  void move(int row, int col) override;
};

class Pawn: public Piece {
 public:
  Pawn(std::shared_ptr<Controller> ctrl,
       int r, int c, char l, std::string co);
  ~Pawn();
  void move(int row, int col) override;
};

#endif
