#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include <memory>
#include "view.h"
#include "board.h"


class TextDisplay: public View {
 std::vector<std::vector<char>> theDisplay;
 public:
        TextDisplay();
        ~TextDisplay();
        void notify(Board *b);
        void setup();
        void setup_add(char letter, int r, int c);
		void setup_delete(int r, int c);
        friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

