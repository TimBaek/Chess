#ifndef _COMPUTER_H_
#define _COMPUTER_H_
#include "board.h"
#include "player.h"
#include <string>

class Computer: public Player {
 	std::string colour;
	bool stalemate;
	bool checkmate;
	bool check;
	Board *b;
	int level;
	int currR,currC,destR,destC;
	std::string randomMove();
 public:
 	Computer(std::string colour, int level);
 	~Computer();
 	std::string getColour();
 	std::string getName();
 	int getX();
	int getY();
	int getDestX();
	int getDestY();
	bool isStalemate();
	bool isCheckmate();
	bool isCheck();
	void setBoard(Board *b);
	void nextMove();
};

#endif
