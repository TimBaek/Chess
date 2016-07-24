#ifndef _COMPUTER_H_
#define _COMPUTER_H_
#include "board.h"
#include "player.h"
#include <string>

class Computer: public Player {
 	std::string colour;
	Board *b;
	int level;
	int score;
	int currR,currC,destR,destC;
	void randomMove();
	void avoidCapture();
	int capturingMove();
	//void avoidCapture2();
 public:
 	Computer(std::string colour, Board *b, int level);
 	~Computer();
 	std::string getColour();
 	std::string getName();
 	int getR();
	int getC();
	int getDestR();
	int getDestC();
	bool isStalemate();
	bool isCheckmate();
	bool isCheck();
	void nextMove();
	void addScore();
	int getScore();
};

#endif
