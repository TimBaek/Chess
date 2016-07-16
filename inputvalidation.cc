#include "inputvalidation.h"
using namespace std;

InputValidation::InputValidation() {}
InputValidation::~InputValidation() {}

bool InputValidation::playerVal(const string& w, const string& b) {
	string wlevel, blevel;
	if (w == "human" && b == "human") return true;
	else if (w == "human" && b.substr(0,8) == "computer") {
		blevel = b.substr(9,1);
		return (blevel == "1" || blevel == "2" || blevel == "3" || blevel == "4");
	}
	else if (w.substr(0,8) == "computer" && b == "human") {
		wlevel = w.substr(9,1);
		return (wlevel == "1" || wlevel == "2" || wlevel == "3" || wlevel == "4");	
	}
	else if (w.substr(0,8) == "computer" && b.substr(0,8) == "computer") {
		wlevel = w.substr(9,1);
		blevel = b.substr(9,1);
		return ((wlevel == "1" || wlevel == "2" || wlevel == "3" || wlevel == "4") && (blevel == "1" || blevel == "2" || blevel == "3" || blevel == "4"));
	}
	else return false;
}

void InputValidation::menuMessage() const{
	cout << "Welcm to Chess!" << endl;
	cout << "Avaliable Commands: [ game white-player black-player ] [ setup ] [ quit ]" << endl;
	cout << "Player Options: [ human | computer[1-4] ]" << endl;
}

void InputValidation::menuErrorMessage() const {
	cerr << "Error! Please enter one of the following: [ game white-player black-player ] [ setup ] [ quit ]" << endl;
}

void InputValidation::gameMessage() const {
	cout << "Avaliable Commands: [ move cord cord]" << endl;
}