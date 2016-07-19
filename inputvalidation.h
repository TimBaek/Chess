#ifndef _INPUTVALIDATION_H_
#define _INPUTVALIDATION_H_
#include <string>
#include <iostream>

class InputValidation {
 public:
 	InputValidation();
 	~InputValidation();
 	bool isPlayer(const std::string& w, const std::string& b);
 	bool isValid(const char& r, const char& c, const char& p = ' ');
 	void currPlayerMessage(std::string& p);
 	void menuMessage() const;
 	void errorMessage() const;
 	void gameMessage() const;
 	void setupMessage() const;
 	void turnMessage(int i) const;
};

#endif
