#ifndef CELL_H
#define CELL_H

#include "Type.h"
#include "Color.h"
#include "Power.h"  
#include <string>

class Cell {
    public:
        Cell ();
        Cell (Type type, int power);
        int getPower();
        std::string printPower();
    protected:
        Power power;
        Type type;
};

extern Cell DEF_CELL;

#endif // CELL_H