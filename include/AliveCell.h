#ifndef ALIVE_CELL_H
#define ALIVE_CELL_H

#include "Cell.h"

class AliveCell: public Cell {
    public:
        AliveCell();
        AliveCell(Type type, int power);
        void setAction(int action);
        int getAction();
    private:
        int action;
};

#endif // ALIVE_CELL_H