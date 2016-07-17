#ifndef __GRAPHICDISPLAY_H__
#define __GRAPHICDISPLAY_H__
#include "view.h"
#include <iostream>
#include <vector>

//class Xwindow;

class GraphicDisplay: public View {
    
	public:
		GraphicDisplay();
		~GraphicDisplay();
		void notify(int ir, int ic, int dr, int dc);
		friend std::ostream &operator<<(std::ostream &out, const GraphicDisplay &td);
};

#endif