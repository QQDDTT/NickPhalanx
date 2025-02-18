#include "AliveCell.h"


AliveCell::AliveCell() : Cell(WHITE, 1) {
    this->action = 0;
}

AliveCell::AliveCell(Type type, int power) : Cell(type, power) {
    this->action = 0;
}

void AliveCell::resetAction() {
    this->action = power.getPower();
}

int AliveCell::getAction() {
    return this->action;
}


void AliveCell::plunder(Cell cell) {
    this->power >> cell.getPower();
}

void AliveCell::dedicate(Cell cell) {
    this->power << cell.getPower();
}
