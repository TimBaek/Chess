#include <ctype.h>
#include <stdio.h>
#include "inputvalidation.h"
using namespace std;

InputValidation::InputValidation() {}
InputValidation::~InputValidation() {}

bool InputValidation::isPlayer(const string& w, const string& b) {
	string wlevel, blevel;
	if (w == "human" && b == "human") return true;
	else if (w == "human" && b.substr(0,8) == "computer") {
		blevel = b.substr(8,1);
		return (blevel == "1" || blevel == "2" || blevel == "3" || blevel == "4");
	} else if (w.substr(0,8) == "computer" && b == "human") {
		wlevel = w.substr(8,1);
		return (wlevel == "1" || wlevel == "2" || wlevel == "3" || wlevel == "4");	
	} else if (w.substr(0,8) == "computer" && b.substr(0,8) == "computer") {
		wlevel = w.substr(8,1);
		blevel = b.substr(8,1);
		return ((wlevel == "1" || wlevel == "2" || wlevel == "3" || wlevel == "4") && (blevel == "1" || blevel == "2" || blevel == "3" || blevel == "4"));
	} else return false;
}

bool InputValidation::isValid(const char& r, char& c, const char& p) {
	if (isupper(c)) c = tolower(c);
	string lpiece = "prnbqk";
	string upiece = "PRNBQK";
	string row = "12345678";
	string column = "abcdefgh";

	if (p != ' ') {
		return ((lpiece.find_first_of(p) != string::npos || upiece.find_first_of(p) != string::npos) && 
				(row.find_first_of(r) != string::npos && column.find_first_of(c) != string::npos));
	}
	else return (row.find_first_of(r) != string::npos && column.find_first_of(c) != string::npos);
}

void InputValidation::currPlayerMessage(string& p) {
	if (p == "white") cout << "White turn: ";
	else cout << "Black turn: ";
}

void InputValidation::level0Message() const {
	cout << "Welcome to Chess!" << endl;
	cout << "Please choose your option of display: [ td ] [ gd ]" << endl;
}

void InputValidation::menuMessage() const{
	cout << endl;
	cout << "Avaliable Commands: [ game white-player black-player ] [ setup ]" << endl;
	cout << "Player Options: [ human | computer[1-4] ]" << endl;
}

void InputValidation::errorMessage() const {
	cerr << "Error! Please re-enter." << endl;
}

void InputValidation::gameMessage() const {
	cout << endl;
	cout << "Human Avaliable Commands: [ move cord cord ] [ move cord cord piece ] [ resign ]" << endl;
	cout << "Computer Avaliable Commands: [ move ] [ resign ]" << endl;
}

void InputValidation::setupMessage() const {
	cout << endl;
	cout << "Avaliable Commands: [ + Piece cord] [ - cord ] [ = colour ] [ done ]" << endl;
}

void InputValidation::checkMessage(const string& colour) {
	if (colour == "white") cout << "White is in check." << endl;
	else cout << "Black is in check." << endl;
}

void InputValidation::checkmateMessage(const string& colour) {
	if (colour == "white") cout << "Checkmate! Black wins!" << endl;
	else cout << "Checkmate! White wins!" << endl;
}

void InputValidation::stalemateMessage() {
	cout << "Stalemate!" << endl;
}

void InputValidation::resignMessage(const string& currPlayer) {
	if (currPlayer == "white") cout << "Black wins!" << endl;
	else cout << "White wins!" << endl;
}

void InputValidation::numKingMessage() const {
	cout << "Error! Players do not have 1 king each!" << endl;
}
 
void InputValidation::badPawnPositionMessage() const {
	cout << "Error! Pawn exists in first or last row!" << endl;
}

void InputValidation::regameMessage() const {
	cout << "Would you like to play again? (y/n): ";
}
