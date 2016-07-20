#ifndef __VIEW_H__
#define __VIEW_H__
#include <iostream>
#include <vector>

class Board;

class View {
 public:
 	View();
 	virtual ~View() = 0;
 	virtual void notify(Board *b) = 0;
 	virtual void print() = 0;
};

#endif
