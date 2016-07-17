#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {

 public:
  Player();
  virtual ~Player();
  virtual std::string getColour() = 0;
  virtual bool isWin() = 0;
  virtual bool isStalemate() = 0;
  virtual bool isCheckmate() = 0;
  virtual std::string getNode() = 0;
};


#endif
