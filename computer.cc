#include "computer.h"
using namespace std;

Computer::Computer(string colour, bool win, bool stalemate, bool checkmate): 
	colour{colour}, 
	win{false}, 
	stalemate{false}, 
	checkmate{false} {}

string Computer::getColour() { return colour; }

bool Computer::isWin() { return win; }

bool Computer::isStalemate() { return stalemate; }

bool Computer::isCheckmate() { return checkmate; }