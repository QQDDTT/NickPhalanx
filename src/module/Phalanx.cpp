#include "Type.h"
#include "Color.h"
#include "Position.h"
#include "Phalanx.h"
#include "Cell.h"

Phalanx::Phalanx() : min_x(0), max_x(9), min_y(0), max_y(9) {
    cells = std::unordered_map<Position, Cell>();
    for (int x = min_x; x <= max_x; x++) {
        for (int y = min_y; y <= max_y; y++) {
            cells[Position(x, y)] = DEF_CELL;
        }
    }
}

Phalanx::Phalanx(int min_x, int max_x, int min_y, int max_y) : min_x(min_x), max_x(max_x), min_y(min_y), max_y(max_y) {
    cells = std::unordered_map<Position, Cell>();
    for (int x = min_x; x <= max_x; x++) {
        for (int y = min_y; y <= max_y; y++) {
            cells[Position(x, y)] = DEF_CELL;
        }
    }
}

Cell Phalanx::getCell(Position position) {
    return cells[position];
}

void Phalanx::setCell(Position position, Cell cell) {
    cells[position] = cell;
}

int Phalanx::getMinX() {
    return min_x;
}

int Phalanx::getMaxX() {
    return max_x;
}

int Phalanx::getMinY() {
    return min_y;
}

int Phalanx::getMaxY() {
    return max_y;
}
