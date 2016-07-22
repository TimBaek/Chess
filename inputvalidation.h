#ifndef _INPUTVALIDATION_H_
#define _INPUTVALIDATION_H_
#include <string>
#include <iostream>

class InputValidation {
 public:
 	InputValidation();
 	~InputValidation();
 	bool isPlayer(const std::string& w, const std::string& b);
 	bool isValid(const char& r, char& c, const char& p = ' ');
 	void currPlayerMessage(std::string& p);
 	void level0Message() const;
 	void menuMessage() const;
 	void errorMessage() const;
 	void gameMessage() const;
 	void setupMessage() const;
 	void numKingMessage() const;
 	void regameMessage() const;
 	void badPawnPositionMessage() const;
 	void checkMessage(const std::string& colour);
 	void checkmateMessage(const std::string& colour);
 	void stalemateMessage();
 	void resignMessage(const std::string& currPlayer);
 	void printScore(const int& w, const int& b);
};

#endif
