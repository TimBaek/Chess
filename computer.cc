#include "computer.h"
using namespace std;

Computer::Computer(string colour): colour{colour}, stalemate{false}, checkmate{false}, check{false} {}

Computer::~Computer() {}

string Computer::getColour() { return colour; }

bool Computer::isStalemate() { return stalemate; }

bool Computer::isCheckmate() { return checkmate; }

bool Computer::isCheck() { return check; }