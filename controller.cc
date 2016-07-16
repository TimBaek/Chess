#include "controller.h"
#include <string>

Controller::Controller(): gameRunning{false} {}
Controller::~Controller() {}

void Controller::game() {
	Player wp, bp;
	try {
		string w, b;
		while (1) {
			in >> w >> b;
			if (iv.playerVal(w,b)) {
				if (w == "human") wp = new Human();
				else wp = new Computer();
				if (b == "human") bp = new Human();
				else bp = new Computer();
				break;
			}
			else throw iv;
		} //while
	} catch (InvalidInput e) {
		throw e;
	}
	iv.gameMessage();
	try {
		string cmd;
		while (in >> cmd) {
			if (cmd == "move") {
				
			}
			else if (cmd == "resign") {}
		}
	} catch () {

	}
}

void Controller::play() {
	in.exceptions(ios::eofbit|ios::failbit);
	iv.menuMessage();
	try {
		string cmd;
		while (in >> cmd) {
			try {
				if (cmd == "game") game();
				else if (cmd == "setup") setup();
				else if (cmd == "quit") break;
				else throw iv;
			} catch (InvalidInput e) {
				e.menuErrorMessage();
			} //input failure for menu
		}
	} catch (ios::failure) {} //eof
}