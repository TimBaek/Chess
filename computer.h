#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include "player.h"
#include <string>

class Computer: public Player {
 	std::string colour;
	bool win;
	bool stalemate;
	bool checkmate;
 public:
 	Computer(std::string colour, bool win, bool stalemate, bool checkmate);
 	~Computer();
 	std::string getColour();
	bool isWin();
	bool isStalemate();
	bool isCheckmate();
	std::string getNode();
};

#endif
