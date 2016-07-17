#include "controller.h"
#include <string>
#include <memory>
using namespace std;

Controller::Controller(): customized{false} {
	shared_ptr<Board> ptrb = make_shared<Board>(*this);
	b = *ptrb;
}
Controller::~Controller() {}

void Controller::notify() {
	//Player->notify
}

void Controller::notifyView() {

}

void Controller::init() {
	try { //Player init
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
		if(!customized) b.init(wp.getColour(), bp.getColour()); //Board init
		// if(!customized) ... //View init
	} catch (InputValidation e) {
		throw e;
	}
}

void Controller::setup() {
	customized = true;
	b.setup();
}

void Controller::game() {
	try {
		init();
		string cmd;
		while (in >> cmd) {
			iv.gameMessage(); //Start new game
			try {
				if (cmd == "move") {

				}
				else if (cmd == "resign") {

				}
				else throw iv;
			} catch (InputValidation e) {
				e.errorMessage();
			}
		}
	} catch (InputValidation e) {
		throw e;
	}
	//customized = false;
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
			} catch (InputValidation e) {
				e.errorMessage();
			} //input failure for menu
		}
	} catch (ios::failure) {} //eof
}