#include "computer.h"
using namespace std;

Computer::Computer(string colour): colour{colour}, win{false}, stalemate{false}, checkmate{false} {}

Computer::~Computer() {}

string Computer::getColour() { return colour; }

bool Computer::isWin() { return win; }

bool Computer::isStalemate() { return stalemate; }

bool Computer::isCheckmate() { return checkmate; }
