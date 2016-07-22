#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

#include "controller.h"

Controller::Controller(): in{&cin}, board{this}, customized{false} {}
Controller::~Controller() {}

void Controller::notify(int r, int c, int destr, int destc) {
	if (currPlayer->getName() == "human") {
		if (!board.canMove(board.checkState(r,c), destr, destc, currPlayerColour) || currPlayer->isCheck()) throw iv;	
	}
	// Castling Move
	if (board.checkState(r,c)->getLetter() == 'k' || board.checkState(r,c)->getLetter() == 'K') {
		if (destr == r && abs(destc - c) == 2) {
			board.castling(r,c,destc);	
		} 
	} 
	board.checkState(r,c)->move(destr,destc); // Regular Move
	board.offEnPassant(currPlayerColour);
	view->notify(&board);
}

void Controller::setNextPlayer() {
	if (currPlayerColour == "white") currPlayer = bp;
	else currPlayer = wp;
}

void Controller::setup() {
	customized = true;
	iv.setupMessage();
	board.setup();
	while (1) {
		cout << "Setup: ";
		try {
			string cmd, colour;
			char p, r, c;
			*in >> cmd;
			if (cmd == "+") {
				*in >> p >> c >> r;
				if (!iv.isValid(r,c,p)) throw iv;
				board.setup_add(p, r-'0'-1, c-'a');	
			} else if (cmd == "-") {
				*in >> c >> r;
				if (!iv.isValid(r,c)) throw iv;
				board.setup_delete(r-'0'-1, c-'a');
			} else if (cmd == "=") {
				*in >> colour;
				if (colour == "white") currPlayerColour = "white";
				else if (colour == "black") currPlayerColour = "black";
				else throw iv;
			} else if (cmd == "done") {
				break;
				//check condtion
				// if true exit
				// else back to loop
			} else throw iv;
		} catch (InputValidation e) {
			e.errorMessage();
		}
	}	
}

void Controller::init() {
	try {
		string w, b;
		*in >> w >> b;
		if (!iv.isPlayer(w,b)) throw iv;

		//Player init
		int level;
		stringstream ss;
		if (w == "human") wp = make_shared<Human>("white");
		else wp = make_shared<Computer>("white", stoi(w.substr(8,1)), &board);
		if (b == "human") bp = make_shared<Human>("black");
		else bp = make_shared<Computer>("black", stoi(b.substr(8,1)), &board);
		
		board.setPlayers(wp,bp);
		if (!customized) currPlayer = wp;
		if (customized) {
			if (currPlayerColour == "white" || currPlayerColour == "") currPlayer = wp;
			else currPlayer = bp;
		}

		//Board init
		if (!customized) board.init();

		//Display init
		view->notify(&board);
	} catch (InputValidation e) {
		throw e;
	}
}

void Controller::game() {
	try {
		init();
		iv.gameMessage(); //Start new game
		while (1) {
			currPlayerColour = currPlayer->getColour();
			cout << endl;
			view->print();
			iv.currPlayerMessage(currPlayerColour);
			try {
				string cmd;
				*in >> cmd;
				if (cmd == "move") {
					string move;
					getline(*in,move);
					vector<string> cord;
					if (move == "") { // move for Computer
						currPlayer->nextMove();
						notify(currPlayer->getR(), currPlayer->getC(), currPlayer->getDestR(), currPlayer->getDestC());
					}
					else {
						istringstream iss{move};
						string tmp;
						while(iss >> tmp) cord.emplace_back(tmp);
						if (cord.size() != 3 && cord.size() != 2) throw iv;
						else if (cord.size() == 2) {
							if (!iv.isValid(cord[0][1],cord[0][0]) || !iv.isValid(cord[1][1],cord[1][0])) throw iv;
							int r,c,destr,destc;
							r = cord[0][1]-'0'-1;
							c = cord[0][0]-'a';	
							destr = cord[1][1]-'0'-1;
							destc = cord[1][0]-'a';
							notify(r,c,destr,destc);
						} else {
							if(!iv.isValid(cord[0][1],cord[0][0],cord[2][0]) || !iv.isValid(cord[1][1],cord[1][0],cord[2][0])) throw iv;
							//cout << "//Call pawn promotion" << endl;
						}
					}
				} else if (cmd == "resign") {
					iv.resignMessage(currPlayerColour);
					break;
				} else throw iv;

				// Display state of the game
				/*if (wp->isCheckmate()) { // checkmate
					iv.checkmateMessage(wp->getColour());
					break;
				}
				if (bp->isCheckmate()) {
					iv.checkmateMessage(bp->getColour());
					break;
				}
				if (wp->isCheck()) iv.checkMessage(wp->getColour()); //check
				if (bp->isCheck()) iv.checkMessage(bp->getColour());
				if (wp->isStalemate() && bp->isStalemate()) iv.stalemateMessage(); */

				setNextPlayer();
			} catch (InputValidation e) {
				e.errorMessage();
			}
		}
		if(customized) customized = false;
	} catch (InputValidation e) {
		throw e;
	}
}

void Controller::play() {
	in->exceptions(ios::failbit|ios::eofbit);
	iv.level0Message();
	string d;
	while (*in >> d) {
		try {
			if (d == "td") {
				view = make_shared<TextDisplay>();
				break;
			} else if (d == "gd") {
				view = make_shared<GraphicDisplay>();
				break;
			} else throw iv;
			
		} catch (InputValidation e) {
			e.errorMessage();
		}
	}

	iv.menuMessage();
	string cmd;
	while (1) {
		cout << "Menu: ";
		try {
			*in >> cmd;
			if (cmd == "game") game();
			else if (cmd == "setup") setup();
			else if (cmd == "quit") break;
			else throw iv;
		} catch (InputValidation e) {
			e.errorMessage();
		} //input failure for menu
	}
}
