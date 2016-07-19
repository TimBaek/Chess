#ifndef _INPUTVALIDATION_H_
#define _INPUTVALIDATION_H_
#include <string>
#include <iostream>

class InputValidation {
 public:
 	InputValidation();
 	~InputValidation();
 	bool canCreatePlayer(const std::string& w, const std::string& b);
 	bool canSetup(const std::string& p = "", const std::string& c = "");
 	int convertChartoInt(const char& c);
 	void menuMessage() const;
 	void errorMessage() const;
 	void gameMessage() const;
 	void setupMessage() const;
 	void turnMessage(int i) const;
};

#endif
