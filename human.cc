#include "human.h"
using namespace std;

Human::Human(string colour): colour{colour}, stalemate{false}, checkmate{false}, check{false} {}

Human::~Human() {}

string Human::getColour() { return colour; }

bool Human::isStalemate() { return stalemate; }

bool Human::isCheckmate() { return checkmate; }

bool Human::isCheck() { return check; }