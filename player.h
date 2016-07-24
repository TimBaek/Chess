#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player {
	int score;
 public:
 	Player();
 	virtual ~Player() = 0;
 	virtual std::string getColour() = 0;
 	virtual std::string getName() = 0;
 	virtual int getR() = 0;
 	virtual int getC() = 0;
 	virtual int getDestR() = 0;
 	virtual int getDestC() = 0;
 	virtual void nextMove() = 0;
 	virtual void addScore() = 0;
 	virtual int getScore() = 0;
};


#endif
