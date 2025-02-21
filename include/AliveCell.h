#ifndef ALIVE_CELL_H
#define ALIVE_CELL_H

#include "Cell.h"
#include "Position.h"

// 活动单元，能够与周围的单元互动

class AliveCell: public Cell {
    public:
        AliveCell();
        AliveCell(Type type, int power);
        AliveCell(Cell& cell);
        virtual ~AliveCell() = default;
        void resetAction();
        int getAction();
    private:
        int action; // 动作次数
};

#endif // ALIVE_CELL_H