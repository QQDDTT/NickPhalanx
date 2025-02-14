#ifndef ALIVE_CELL_H
#define ALIVE_CELL_H

#include "Cell.h"
#include "Position.h"

class AliveCell: public Cell {
    public:
        AliveCell();
        AliveCell(Type type, int power);
        void setAction(int action);
        int getAction();

        // void move(Position from, Position to);
        // void plunder(Position from, Position to);
        // void dedicate(Position from, Position to);
        // void build(Position from, Position to);
    private:
        int action;
};

#endif // ALIVE_CELL_H