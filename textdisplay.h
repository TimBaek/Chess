#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include <memory>
#include "view.h"


class TextDisplay: public View {
 std::vector<std::vector<char>> theDisplay;
 public:
 	TextDisplay();
 	~TextDisplay();
 	void notify(Board *b);
 	void print();
};

#endif

