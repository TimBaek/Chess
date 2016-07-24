#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player {
	double score;
 public:
 	Player();
 	void addScore(const double& s);
 	double getScore();
 	virtual ~Player() = 0;
 	virtual std::string getColour() = 0;
 	virtual std::string getName() = 0;
 	virtual int getR() = 0;
 	virtual int getC() = 0;
 	virtual int getDestR() = 0;
 	virtual int getDestC() = 0;
 	virtual void nextMove() = 0;
};


#endif
