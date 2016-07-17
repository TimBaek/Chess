#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "inputvalidation.h"
#include "player.h"
#include "board.h"
#include <iostream>

class Controller {
	std::istream *in;
	Player wp, bp;
	//View td, gd;
	Board b;
	InputValidation iv;
 	bool customized;
 public:
 	Controller();
 	~Controller();
 	void init();
 	void play();
 	void game();
 	void setup();
 	void notify(); //notify the Piece 
 	void notifyView(); //notify the View
};

#endif