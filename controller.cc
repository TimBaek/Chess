#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "controller.h"

Controller::Controller(): in{0}, board{this}, customized{false} {}
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
				if (w == "human") wp = make_shared<Human>("white");
				else wp = make_shared<Computer>("white");
				if (b == "human") bp = make_shared<Human>("black");
				else bp = make_shared<Computer>("black");
				break;
			}
			else throw iv;
		}
		if(!customized) board.init(wp->getColour(), bp->getColour()); //Board init
		if(!customized) td = make_shared<TextDisplay>();
	} catch (InputValidation e) {
		throw e;
	}
}

void Controller::setup() {
	customized = true;
	iv.setupMessage();
	//b.setup();
}

void Controller::game() {
	try {
		init();
		iv.gameMessage(); //Start new game
		cout << td;
		string cmd;
		while (*in >> cmd) {
			try {
				if (cmd == "move") {
					vector<string> commands;
					string line;
					getline(*in,cords);
					if (line == "") // move  for Computer
					else {
						istringstream iss{line};
						string tmp;
						while(iss >> tmp) commands.emplace_back(tmp);
						if (commands.size() != 3 || commands.size() != 2) throw iv;
						else if (commands.size() == 2) //Call piece move
						else //Call pawn promotion
					}
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