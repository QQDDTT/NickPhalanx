#ifndef PHALANX_H
#define PHALANX_H

#include "Cell.h"
#include "Position.h"
#include "Step.h"
#include "AliveCell.h"
#include "View.h"

#include <string>
#include <unordered_map>

// Phalanx类，用于储存和管理单元

class Phalanx {
    public:
        Phalanx();
        Phalanx(int min_x, int max_x, int min_y, int max_y);
        Cell* getCell(Position position);
        void setCell(Position position, Cell* cell);
        int getStep();
        std::unordered_map<Position, Cell*> getCells();
        std::unordered_map<Position, AliveCell*> getAliveCells();
        std::unordered_map<Position, Cell*> getNeighors(Position position);
        int getMinX();
        int getMaxX();
        int getMinY();
        int getMaxY();
        int getDistance(Position position1, Position position2);
        void nextStep();
        bool move(Position from, Position to);
        bool plunder(Position from, Position to);
        bool dedicate(Position from, Position to);
        bool copy(Position from, Position to);

    private:
        Step step; // 回合数
        std::unordered_map<Position, Cell*> cells; // 储存单元的表格
        // 二元空间的边界
        int min_x;
        int max_x;
        int min_y;
        int max_y;
};


#endif // PHALANX_H