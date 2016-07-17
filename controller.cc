#include "controller.h"
#include <string>
using namespace std;

Controller::Controller(): b{this}, customized{false} {}
Controller::~Controller() {}

void Controller::notify() {
	//Player->notify
}

void Controller::notifyView() {

}

void Controller::init() {
	//Player init
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
		}
	} catch (InvalidInput e) {
		throw e;
	}
	//Board init
	if(!customized) b.init(wp.getColour(), bp.getColour());
	//View init
	// if(!customized) ...
}

void Controller::setup() {

}

void Controller::game() {
	iv.gameMessage(); //Start new game
	init();
	try {
		string cmd;
		while (in >> cmd) {
			if (cmd == "move") {

			}
			else if (cmd == "resign") {

			}
			else throw iv;
		}
	} catch (InvalidInput e) {
		e.errorMessage();
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
				e.errorMessage();
			} //input failure for menu
		}
	} catch (ios::failure) {} //eof
}