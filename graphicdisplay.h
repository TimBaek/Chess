#ifndef __GRAPHICDISPLAY_H__
#define __GRAPHICDISPLAY_H__
#include <iostream>
#include <vector>
#include <memory>
#include "view.h"
#include "window.h"


class Board;

class GraphicDisplay: public View {
        std::shared_ptr<Xwindow> xw;
        int side, origin, line, dimension;
        std::vector<std::vector<char>> theDisplay;
 public:
        GraphicDisplay(std::shared_ptr<Xwindow> xw);
        ~GraphicDisplay();
        void notify(Board *b);
        void print();
};

#endif
