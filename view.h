#ifndef __VIEW_H__
#define __VIEW_H__
#include <iostream>
#include <vector>

class View {

   public:
        View();
        virtual ~View() = 0;
        virtual void notify(int ir, int ic, int dr, int dc) = 0;
};

#endif