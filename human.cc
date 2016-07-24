#include "human.h"
using namespace std;

Human::Human(string colour): colour{colour} {}

Human::~Human() {}

string Human::getName() { return "human"; }
string Human::getColour() { return colour; }

int Human::getR(){ return -1; }

int Human::getC(){ return -1; }
int Human::getDestR(){ return -1; }
int Human::getDestC(){ return -1; }

void Human::nextMove(){}