#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include "player.h"
#include <string>

class Computer: public Player {
 	std::string colour;
	bool stalemate;
	bool checkmate;
	bool check;
 public:
 	Computer(std::string colour);
 	~Computer();
 	std::string getColour();
	bool isStalemate();
	bool isCheckmate();
	bool isCheck();
};

#endif
