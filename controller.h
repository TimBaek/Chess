#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <memory>
#include <string>

#include "inputvalidation.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include "board.h"
//#include "view.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

class Controller {
	std::istream *in;
	std::string currPlayer;
	std::shared_ptr<Player> wp, bp;
	std::shared_ptr<TextDisplay> td;
	std::shared_ptr<GraphicDisplay> gd;
	Board board;
	InputValidation iv;
 	bool customized;
 	void setcurrPlayer();
 public:
 	Controller();
 	~Controller();
 	void init();
 	void play();
 	void game();
 	void setup();
 	void notify(int r, int c, int destr, int destc); //notify the Piece
};

#endif