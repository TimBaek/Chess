#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include "view.h"
#include <iostream>
#include <vector>

class View;

class TextDisplay: public View {
  std::vector<std::vector<char>> theDisplay;
 public:
  TextDisplay(int n);

  void notify(int, int, int, int, char move) override;
  void print (std::ostream &out); 

  ~TextDisplay();
};

#endif