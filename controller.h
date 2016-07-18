#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <memory>

#include "inputvalidation.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include "board.h"
#include "view.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

class Controller {
	std::istream *in;
	std::shared_ptr<Player> wp, bp;
	std::shared_ptr<TextDisplay> td;
	std::shared_ptr<GraphicDisplay> gd;
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