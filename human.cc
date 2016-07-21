#include "human.h"
using namespace std;

Human::Human(string colour): colour{colour}, stalemate{false}, checkmate{false}, check{false} {}

Human::~Human() {}

string Human::getName() { return "human"; }
string Human::getColour() { return colour; }

bool Human::isStalemate() { return stalemate; }

bool Human::isCheckmate() { return checkmate; }

bool Human::isCheck() { return check; }

int Human::getR(){ return -1; }

int Human::getC(){ return -1; }
int Human::getDestR(){ return -1; }
int Human::getDestC(){ return -1; }

void nextMove(){ }