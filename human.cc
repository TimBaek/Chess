#include "human.h"
using namespace std;

Human::Human(string colour, bool win, bool stalemate, bool checkmate): 
	colour{colour}, 
	win{false}, 
	stalemate{false}, 
	checkmate{false} {} 

string Human::getColour() { return colour; }

bool Human::isWin() { return win; }

bool Human::isStalemate() { return stalemate; }

bool Human::isCheckmate() { return checkmate; }