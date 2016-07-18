#include <iostream>
#include "graphicdisplay.h"
using namespace std;

GraphicDisplay::GraphicDisplay() {
  
}


void GraphicDisplay::notify(Board *b) {
}

// dtor
GraphicDisplay::~GraphicDisplay() {}

ostream &operator<<(ostream &out, const GraphicDisplay &td) {
	/*
	for(int c=0; c < 8; ++c) {
		for(int r=0; r < 8; ++r) {
			out << currStates[r][c];	
		}
		out << endl;
	}
	*/
	return out;
}