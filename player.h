#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {

 public:
  Player();
  ~Player();
  std::string getColour();
  bool isWin();
  bool isStalemate();
  bool isCheckmate();
  std::string getNode();
};


#endif
