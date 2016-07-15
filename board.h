#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <vector>
#include "piece.h"
#include "textdisplay.h"

class Board {
  std::vector<Piece> P1;
  std::vector<Piece> P2;
  std::vector<std::vector<char>> currStates;  // current state of the board
  TextDisplay *td; // The text display.
  GraphicDisplay *gd; // The graphic display.

  void clearBoard();   // Frees the board.
  void defaultSetup(Player *player1, Player *player2);

 public:
  Board(TextDisplay *td, GraphicDisplay *gd);
  ~Board();
  
  //void notifyTd(TextDisplay *td);
  void notify(int r, int c, int destr, int destc);

  bool isThere(Piece &p, int r, int c);
  bool canMove(Pice &p, int r, int c);
  void updateState();
  void init(Player *player1, Player *player2);
  void setup();
  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
