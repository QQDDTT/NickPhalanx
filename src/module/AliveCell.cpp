#include "AliveCell.h"


AliveCell::AliveCell() : Cell(WHITE, 1) {
    this->action = 0;
}

AliveCell::AliveCell(Type type, int power) : Cell(type, power) {
    this->action = 0;
}

void AliveCell::setAction(int action) {
    this->action = action;
}

int AliveCell::getAction() {
    return this->action;
}

