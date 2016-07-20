#include "human.h"
using namespace std;

Human::Human(string colour): colour{colour}, win{false}, stalemate{false}, checkmate{false} {}

Human::~Human() {}

string Human::getColour() { return colour; }

bool Human::isWin() { return win; }

bool Human::isStalemate() { return stalemate; }

bool Human::isCheckmate() { return checkmate; }
