#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include "player.h"
#include <string>

class Computer: public Player {
 public:
 	Computer();
 	~Computer();
 	std::string getColour();
	bool isWin();
	bool isStalemate();
	bool isCheckmate();
	std::string getNode();
};

#endif
