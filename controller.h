#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <memory>

#include "inputvalidation.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include "board.h"

class Controller {
	std::istream *in;
	std::shared_ptr<Player> wp, bp;
	//View td, gd;
	Board board;
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