#ifndef _INPUTVALIDATION_H_
#define _INPUTVALIDATION_H_

#include <iostream>

class InputValidation {
 public:
 	InputValidation();
 	~InputValidation();
 	bool playerVal(const string& w, const string& b);
 	void menuMessage() const;
 	void menuErrorMessage() const;
 	void gameMessage() const;
};

#endif