#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player {
 public:
 	Player();
 	virtual ~Player() = 0;
 	virtual std::string getColour() = 0;
 	virtual bool isStalemate() = 0;
 	virtual bool isCheck() = 0;
 	virtual bool isCheckmate() = 0;
};


#endif
