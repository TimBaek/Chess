#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "view.h"

class TextDisplay: public View {
 std::vector<std::vector<char>> theDisplay;
 public:
        TextDisplay();
        ~TextDisplay();
        void notify(int ir, int ic, int dr, int dc);
        void setup();
        void setup_add(char letter, int r, int c);
		void setup_delete(int r, int c);
        friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif