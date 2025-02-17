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

        void plunder(Cell cell);
        void dedicate(Cell cell);
    private:
        int action;
};

#endif // ALIVE_CELL_H