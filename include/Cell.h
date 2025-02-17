#ifndef CELL_H
#define CELL_H

#include "Type.h"
#include "Power.h"
#include "Position.h"  
#include <string>

// Cell class
class Cell {
    public:
        static Cell DEF();
        Cell ();
        Cell (Type type, int power);
        int getPower();
        void printPower();
    protected:
        Power power;
        Type type;
};

#endif // CELL_H