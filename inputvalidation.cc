#include "inputvalidation.h"
using namespace std;

InputValidation::InputValidation() {}
InputValidation::~InputValidation() {}

bool InputValidation::canCreatePlayer(const string& w, const string& b) {
	string wlevel, blevel;
	if (w == "human" && b == "human") return true;
	else if (w == "human" && b.substr(0,8) == "computer") {
		blevel = b.substr(9,1);
		return (blevel == "1" || blevel == "2" || blevel == "3" || blevel == "4");
	} else if (w.substr(0,8) == "computer" && b == "human") {
		wlevel = w.substr(9,1);
		return (wlevel == "1" || wlevel == "2" || wlevel == "3" || wlevel == "4");	
	} else if (w.substr(0,8) == "computer" && b.substr(0,8) == "computer") {
		wlevel = w.substr(9,1);
		blevel = b.substr(9,1);
		return ((wlevel == "1" || wlevel == "2" || wlevel == "3" || wlevel == "4") && (blevel == "1" || blevel == "2" || blevel == "3" || blevel == "4"));
	} else return false;
}

bool InputValidation::canSetup(const std::string& p = "", const std::string& c = "") {
	if (p != "" && c != "") {
		return ((p.find_first_of("PRNBQK") != string::npos || p.find_first_of("prnbqk") != string::npos) && 
				(c[0].find_first_of("abcdefgh") != string::npos && c[1].find_first_of("12345678") != string::npos));
	} else return (c[0].find_first_of("abcdefgh") != string::npos && c[1].find_first_of("12345678") != string::npos);
}

int InputValidation::convertChartoInt(const char& c) {
	return c - 'a';
}

void InputValidation::menuMessage() const{
	cout << "Welcm to Chess!" << endl;
	cout << "Avaliable Commands: [ game white-player black-player ] [ setup ] [ quit ]" << endl;
	cout << "Player Options: [ human | computer[1-4] ]" << endl;
}

void InputValidation::errorMessage() const {
	cerr << "Error! Please re-enter the inputs" << endl;
}

void InputValidation::gameMessage() const {
	cout << "Human Avaliable Commands: [ move cord cord ] [ move cord cord cord ] [ resign ]" << endl;
	cout << "Computer Avaliable Commands: [ move ] [ resign ]" << endl;
}

void InputValidation::setupMessage() const {
	cout << "Avaliable Commands: [ + Piece cord] [ - cord ] [ = colour ] [ done ]" << endl;
}

void InputValidation::turnMessage(int i) const {
	cout << "Player " << i << ". Enter command: " << endl;
}