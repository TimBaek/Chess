#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "player.h"
#include <string>

class Human: public Player {
	std::string colour;
	int score;
 public:
	Human(std::string colour);
	~Human();
	std::string getColour();
	std::string getName();
	int getR();
 	int getC();
 	int getDestR();
 	int getDestC();
 	void nextMove();
	void addScore();
	int getScore();
};

#endif
