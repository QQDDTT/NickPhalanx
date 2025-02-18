#ifndef PHALANX_H
#define PHALANX_H

#include "Cell.h"
#include "Position.h"
#include "Step.h"
#include "AliveCell.h"
#include "View.h"

#include <string>
#include <unordered_map>

class Phalanx {
    public:
        Phalanx();
        Phalanx(int min_x, int max_x, int min_y, int max_y);
        Cell getCell(Position position);
        void setCell(Position position, Cell cell);
        int getMinX();
        int getMaxX();
        int getMinY();
        int getMaxY();
        int getDistance(Position position1, Position position2);
        void nextStep();
    private:
        Step step;
        std::unordered_map<Position, Cell> cells;
        int min_x;
        int max_x;
        int min_y;
        int max_y;
};


#endif // PHALANX_H