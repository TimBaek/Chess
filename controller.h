#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <memory>
#include <string>

#include "inputvalidation.h"
#include "board.h"
#include "textdisplay.h"
#include "graphicdisplay.h"
#include "human.h"
#include "computer.h"

class Controller {
	std::istream *in;
	std::string currPlayer;
	std::shared_ptr<Player> wp,bp;
	std::shared_ptr<View> view;
	Board board;
	InputValidation iv;
 	bool customized;
 	void setNextPlayer();
 	void init();
 public:
 	Controller();
 	~Controller();
 	void play();
 	void game();
 	void setup();
 	void notify(int r, int c, int destr, int destc); //notify the Piece
};

#endif