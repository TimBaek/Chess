#ifndef __GRAPHICDISPLAY_H__
#define __GRAPHICDISPLAY_H__
#include <iostream>
#include <vector>

class GraphicDisplay {
    
	public:
		GraphicDisplay();
		~GraphicDisplay();
		void notify(int ir, int ic, int dr, int dc);
		friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif