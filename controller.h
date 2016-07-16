#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "inputvalidation.h"
#include <iostream>

class Controller {
	std::istream *in;
	InputValidation iv;
 	bool gameRunning;
 public:
 	Controller();
 	~Controller();
 	void play();
 	void game();
};

#endif