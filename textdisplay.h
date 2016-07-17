#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "board.h"
#include "piece.h"

class Board;

class TextDisplay {
 public:
        TextDisplay();
        ~TextDisplay();
        void notify(int ir, int ic, int dr, int dc);
        friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif