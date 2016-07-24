#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <vector>
#include "piece.h"
#include "player.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

class Controller;
class Human;
class Computer;
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
  std::shared_ptr<Player> wp, bp;
  std::vector<std::vector<std::shared_ptr<Piece>>> currStates;  // current state of the board

  void defaultSetup(std::string colour1, std::string colour2);
  void updateState(int r, int c, int destr, int destc);

 public:
  Board(Controller *ctrl);
  ~Board();
  
  //void notifyTd(TextDisplay *td);
  void notify(int r, int c, Piece &p);

  bool isThere(Piece &p, int r, int c);
  void offEnPassant(std::string colour);
  void castling(int r, int c, int destc);
  bool canMove(std::shared_ptr<Piece> p, int destr, int destc, std::string col);
  bool canMoveK(std::shared_ptr<Piece> p, int destr, int destc, std::string col);
  bool canMoveQ(std::shared_ptr<Piece> p, int destr, int destc, std::string col);
  bool canMoveR(std::shared_ptr<Piece> p, int destr, int destc, std::string col);
  bool canMoveN(std::shared_ptr<Piece> p, int destr, int destc, std::string col);
  bool canMoveB(std::shared_ptr<Piece> p, int destr, int destc, std::string col);
  bool canMoveP(std::shared_ptr<Piece> p, int destr, int destc, std::string col);
  //TextDisplay &getTd() const;
  //void init(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
  void init();
  void setPlayers(std::shared_ptr<Player> w, std::shared_ptr<Player> b);
  void setup();
  void setup_add(char letter, int r, int c);
  void setup_delete(int r, int c);
  int numKing(std::string colour);
  int numPieces(std::string colour);
  bool isEmpty(int r, int c);
  bool isbadPawnPosition();
  char getLetter(int r, int c);
  std::shared_ptr<Piece> checkState(int r, int c);
  bool isPromo(int r, int c, int destr, int destc);
  bool willBeChecked(int r, int c, int dr, int dc, std::string colour);
  bool isCheck(std::string colour);
  bool isCheckmate(std::string colour);
  bool isStalemate(std::string colour);
};

#endif
