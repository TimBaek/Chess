#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

#include "controller.h"

Controller::Controller(): in{&cin}, currPlayerColour{"white"}, board{this}, customized{false} {}
Controller::~Controller() {}

void Controller::setNextPlayer() {
	if (currPlayer->getColour() == "white") currPlayer = bp;
	else currPlayer = wp;
}

void Controller::calculateScore(string colour, double s) {
	if (colour == "white") wp->addScore(s);
	else bp->addScore(s);
}

void Controller::printScore() {
	cout << endl;
	cout << "Final score:" << endl;
	cout << "White: " << wp->getScore() << endl;
	cout << "Black: " << bp->getScore() << endl;
	cout << endl;
}

void Controller::rebuild() {
	board.init();
	view->notify(&board);
	currPlayer = wp;
}

void Controller::notify(int r, int c, int destr, int destc, char piece) {
	if (currPlayer->getName() == "human") {
		if (!board.canMove(board.checkState(r,c), destr, destc, currPlayer->getColour())) throw iv;
	}
	if (board.willBeChecked(r,c,destr,destc,currPlayer->getColour())) throw iv;

	// Castling Move
	if ((board.checkState(r,c)->getLetter() == 'k' || board.checkState(r,c)->getLetter() == 'K') &&
		!board.willBeChecked(-1,-1,-1,-1,currPlayer->getColour())) {
		if (destr == r && abs(destc - c) == 2) {
			board.castling(r,c,destc);	
		} 
	}
	// EnPassant Move
	else if (board.checkState(r,c)->getLetter() == 'p' || board.checkState(r,c)->getLetter() == 'P') {
		if (abs(destr -r) == 1 && abs(destc -c) == 1 &&
			board.isEmpty(destr,destc)) {
			if (currPlayer->getColour() == "white") board.setup_delete(destr -1,destc);
			else board.setup_delete(destr +1, destc);
		} 
	}
	board.offEnPassant(currPlayer->getColour());
	board.checkState(r,c)->move(destr,destc); // Regular Move

	if (piece != ' ') { // Pawn Promotion
		board.setup_delete(destr,destc);
		board.setup_add(piece,destr,destc);
	}
	view->notify(&board);
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
				if (board.numKing("white") != 1 || board.numKing("black") != 1) iv.numKingMessage();
				else if (!board.isbadPawnPosition()) iv.badPawnPositionMessage();
				//ischeck
				else break;
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
		if (w == "human") wp = make_shared<Human>("white");
		else wp = make_shared<Computer>("white", &board, stoi(w.substr(8,1)));
		if (b == "human") bp = make_shared<Human>("black");
		else bp = make_shared<Computer>("black", &board, stoi(b.substr(8,1)));
		board.setPlayers(wp,bp);
		
		if (currPlayerColour == "white") currPlayer = wp;
		else currPlayer = bp;

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
			cout << endl;
			view->print();
			try {
				// check if currentPlayer's king is in Check
				if (board.isCheckmate(currPlayer->getColour())) {
					iv.checkmateMessage(currPlayer->getColour());
					calculateScore((currPlayer->getColour() == "white" ? "black" : "white"), 1);
					throw 1;
				}
				if (board.isStalemate(currPlayer->getColour())) {
					iv.stalemateMessage();
					calculateScore("white", 0.5);
					calculateScore("black", 0.5);
					throw 1;
				}
				if (board.isCheck(currPlayer->getColour())) {
					iv.checkMessage(currPlayer->getColour());
				}
				iv.currPlayerMessage(currPlayer->getColour());

				string cmd;
				*in >> cmd;
				if (cmd == "move") {
					string move;
					getline(*in,move);
					vector<string> cord;
					if (move == "" && currPlayer->getName() == "computer") { // move for Computer
						currPlayer->nextMove();
						notify(currPlayer->getR(), currPlayer->getC(), currPlayer->getDestR(), currPlayer->getDestC());
					}
					else {
						istringstream iss{move};
						string tmp;
						while(iss >> tmp) cord.emplace_back(tmp);
						if (cord.size() != 3 && cord.size() != 2) throw iv;
						else {
							int r,c,destr,destc;
							char piece = ' ';
							if (cord.size() == 2) {
								if (!iv.isValid(cord[0][1],cord[0][0]) || !iv.isValid(cord[1][1],cord[1][0])) throw iv;
							} else {
								if(!iv.isValid(cord[0][1],cord[0][0],cord[2][0]) || !iv.isValid(cord[1][1],cord[1][0],cord[2][0])) throw iv;
								if (!board.isPromo(cord[0][1]-'0'-1, cord[0][0]-'a', cord[1][1]-'0'-1, cord[1][0]-'a') || (cord[2][0] == 'k' || cord[2][0] == 'K')) throw iv;
								if (currPlayer->getColour() == "white" && islower(cord[2][0])) piece = toupper(cord[2][0]);
								else if (currPlayer->getColour() == "black" && isupper(cord[2][0])) piece = tolower(cord[2][0]);
								else piece = cord[2][0];
							}
							r = cord[0][1]-'0'-1;
							c = cord[0][0]-'a';	
							destr = cord[1][1]-'0'-1;
							destc = cord[1][0]-'a';
							notify(r,c,destr,destc,piece);
						}
					}
				} else if (cmd == "resign") {
					iv.resignMessage(currPlayer->getColour());
					calculateScore((currPlayer->getColour() == "white" ? "black" : "white"), 1);
					throw 1;
				} else throw iv;

				setNextPlayer();
			} catch (int e) {
				string ans;
				iv.regameMessage();
				*in >> ans;
				if (ans == "Y" || ans == "y") {
					rebuild();
				} else {
					break;
				}
			} catch (InputValidation e) {
				e.errorMessage();
			}
		}
		printScore();
		throw 1;
	} catch(int e) {
		throw e;
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
				shared_ptr<Xwindow> xw = make_shared<Xwindow>();
				view = make_shared<GraphicDisplay>(xw);
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
			else throw iv;
		} catch (int e) {
			break;
		} catch (InputValidation e) {
			e.errorMessage();
		} //input failure for menu
	}
}
