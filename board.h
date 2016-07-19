#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <vector>
#include "piece.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

class Controller;
class King;
class Queen;
class Rook;
class Knight;
class Bishop;
class Pawn;

class Board {
  //std::vector<Piece> P1;
  //std::vector<Piece> P2;
  Controller *ctrl; // The Controller
  std::string player1;
  std::string player2;
  std::vector<std::vector<std::shared_ptr<Piece>>> currStates;  // current state of the board
  std::vector<std::vector<std::vector<int>>> blackMoves; // possible moves for Black player
  std::vector<std::vector<std::vector<int>>> whiteMoves; // possible moves for White player

  void defaultSetup(std::string colour1, std::string colour2);
  void updateState(int r, int c, int destr, int destc);
  void updatePossibleMove();
  void updatePiece(std::shared_ptr<Piece> p);

 public:
  Board(Controller *ctrl);
  ~Board();
  
  //void notifyTd(TextDisplay *td);
  void notify(int r, int c, Piece &p);

  bool isThere(Piece &p, int r, int c);
  bool canMove(King *k, int destr, int destc);
  bool canMove(Queen *q, int destr, int destc);
  bool canMove(Rook *rk, int destr, int destc);
  bool canMove(Knight *n, int destr, int destc);
  bool canMove(Bishop *b, int destr, int destc);
  bool canMove(Pawn *p, int destr, int destc);
  //TextDisplay &getTd() const;
  //void init(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
  void init(std::string p1, std::string p2);
  void setup();
  void setup_add(char letter, int r, int c);
  void setup_delete(int r, int c);
  int numKing(std::string colour);
  int numPieces(std::string colour);
  bool isEmpty(int r, int c);
  char getLetter(int r, int c);
  std::shared_ptr<Piece> checkState(int r, int c);
};

#endif
