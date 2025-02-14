#ifndef CELL_H
#define CELL_H

#include "Type.h"
#include "Color.h"
#include "Power.h"
#include "Position.h"  
#include <string>

class Cell {
    public:
        static Cell DEF();
        Cell ();
        Cell (Type type, int power);
        int getPower();
        std::string printPower();
    protected:
        Power power;
        Type type;
};

#endif // CELL_H