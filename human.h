#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "player.h"
#include <string>

class Human: public Player {
 public:
	Huamn();
	~Human();
	std::string getColour();
	bool isWin();
	bool isStalemate();
	bool isCheckmate();
	std::string getNode();
};

#endif