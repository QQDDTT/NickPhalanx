#ifndef VIEW_H
#define VIEW_H

#include "Phalanx.h"
#include <iostream>
#include <string>

class Phalanx;

// 视图类，用于输出信息

class View {
    public:
        View();
        void operator<<(Phalanx& phalanx);
        void operator<<(Cell& cell);
};

extern View view;



#endif // VIEW_H