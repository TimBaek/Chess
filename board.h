#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <vector>
#include "piece.h"
#include "textdisplay.h"

class TextDisplay;
class GraphicDisplay;
class Controller;

class Board {
  //std::vector<Piece> P1;
  //std::vector<Piece> P2;
  Controller *ctrl; // The Controller
  std::string player1;
  std::string player2;
  std::vector<std::vector<std::shared_ptr<Piece>>> currStates;  // current state of the board
  //std::vector<std::vector<std::std::vector<int>>> possibleMove; // possibleMoves
 
  void clearBoard();   // Frees the board.
  void defaultSetup(std::string colour1, std::string colour2);
  void updateState(int r, int c, int destr, int destc);

 public:
  Board(Controller *ctrl);
  ~Board();
  
  //void notifyTd(TextDisplay *td);
  void notify(int r, int c, Piece &p);

  bool isThere(Piece &p, int r, int c);
  bool canMove(Piece &p, int r, int c);
  //void init(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
  void init(std::string p1, std::string p2);
  void setup();
  void setup_add(char letter, int r, int c);
  void setup_delete(int r, int c);
  int setup_numKing(std::string colour);
  std::shared_ptr<Piece> checkState(int r, int c);
  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
