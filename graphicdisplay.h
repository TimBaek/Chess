#ifndef __GRAPHICDISPLAY_H__
#define __GRAPHICDISPLAY_H__
#include <iostream>
#include <vector>
#include "board.h"
#include "piece.h"

class Board;

class GraphicDisplay: public View {
    
	public:
		GraphicDisplay();
		~GraphicDisplay();
		void notify(int ir, int ic, int dr, int dc) override;
		friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif