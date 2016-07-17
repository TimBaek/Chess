#include "controller.h"
#include <string>
using namespace std;

Controller::Controller(): in{0}, b{this}, customized{false} {}
Controller::~Controller() { delete in; }

void Controller::notify() {
	//Player->notify
}

void Controller::notifyView() {

}

void Controller::init() {
	try { //Player init
		string w, b;
		while (1) {
			*in >> w >> b;
			if (iv.playerVal(w,b)) {
				if (w == "human") wp = new Human("white");
				else wp = new Computer("white");
				if (b == "human") bp = new Human("black");
				else bp = new Computer("black");
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
	iv.setupMessage();
	b.setup();
}

void Controller::game() {
	try {
		init();
		string cmd;
		while (*in >> cmd) {
			iv.gameMessage(); //Start new game
			try {
				if (cmd == "move") {
					string line;
					getline(in,line);
					
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
	in->exceptions(ios::failbit|ios::eofbit);
	iv.menuMessage();
	try {
		string cmd;
		while (*in >> cmd) {
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