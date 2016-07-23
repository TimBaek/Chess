#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>
#include <memory>
#include <string>

#include "inputvalidation.h"
#include "board.h"
#include "view.h"
#include "textdisplay.h"
#include "graphicdisplay.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include "window.h"

class Controller {
	std::istream *in;
	std::string currPlayerColour;
	std::shared_ptr<Player> wp,bp,currPlayer;
	std::shared_ptr<View> view;
	Board board;
	InputValidation iv;
 	bool customized;
 	void setNextPlayer();
 	void init();
 	void calculateScore(std::string colour);
 	void rebuild();
 	void printScore(const int& w, const int& b);
 public:
 	Controller();
 	~Controller();
 	void play();
 	void game();
 	void setup();
 	void notify(int r, int c, int destr, int destc, char piece = ' '); //notify the Piece
};

#endif