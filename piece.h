#ifndef _PIECE_H
#define _PIECE_H
#include <memory>
#include <string>

class Board;

class Piece {
 protected:
  std::shared_ptr<Board> board;
  int row;
  int col;
  std::string colour;

 public:
  Piece(std::shared_ptr<Board> bd, int r, int c, std::string co);
  virtual ~Piece();
  void notifyBoard(int dr, int dc);
  virtual void move(int dr, int dc)=0;
  int getRow() const;
  int getCol() const;
  virtual char getLetter()=0;
  std::string getColour() const;
};

class King: public Piece {
  bool moved = false;

 public:
  King(std::shared_ptr<Board> bd, int r, int c, std::string co, bool b=false);
  ~King();
  void move(int dr, int dc) override;
  bool everMoved();
  char getLetter() override;
};

class Queen: public Piece {
 public:
  Queen(std::shared_ptr<Board> bd, int r, int c, std::string co);
  ~Queen();
  void move(int dr, int dc) override;
  char getLetter() override;
};

class Rook: public Piece {
  bool moved = false;

 public:
  Rook(std::shared_ptr<Board> bd, int r, int c, std::string co, bool b=false);
  ~Rook();
  void move(int dr, int dc) override;
  bool everMoved();
  char getLetter() override;
};

class Knight: public Piece {
 public:
  Knight(std::shared_ptr<Board> bd, int r, int c, std::string co);
  ~Knight();
  void move(int dr, int dc) override;
  char getLetter() override; 
};

class Bishop: public Piece {
 public:
  Bishop(std::shared_ptr<Board> bd, int r, int c, std::string co);
  ~Bishop();
  void move(int dr, int dc) override;
  char getLetter() override;
};

class Pawn: public Piece {
  bool moved = false;
  
 public:
  Pawn(std::shared_ptr<Board> bd, int r, int c, std::string co, bool b=false);
  ~Pawn();
  void move(int dr, int dc) override;
  char getLetter() override;
  bool everMoved();
};

#endif
