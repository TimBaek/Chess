#include <iostream>
#include "graphicdisplay.h"
using namespace std;

GraphicDisplay::GraphicDisplay() {
  for(int i=0; i<8; i++) {
        currStates.push_back(vector<char>(8));
        for(int j=0; j<8; j++) {
                currStates[i][j] = nullptr;
        }
  }
}


void GraphicDisplay::notify(int ir, int ic, int dr, int dc) {
}

// dtor
GraphicDispaly::~GraphicDisplay() {}

ostream &operator<<(ostream &out, const GraphicDisplay &td) {
	for(int c=0; c < 8; ++c) {
		for(int r=0; r < 8; ++r) {
			out << currStates[r][c];	
		}
		out << endl;
	}
	return out;
}