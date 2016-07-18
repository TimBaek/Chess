#ifndef __GRAPHICDISPLAY_H__
#define __GRAPHICDISPLAY_H__
#include <iostream>
#include <vector>
#include "board.h"
#include "view.h"

//class Xwindow;

class GraphicDisplay: public View {
    
	public:
		GraphicDisplay();
		~GraphicDisplay();
		void notify(Board *b);
		friend std::ostream &operator<<(std::ostream &out, const GraphicDisplay &td);
};

#endif
