#include "Cell.h"

Cell::Cell() : power(0), type(DEF) {}

Cell::Cell(Type type, int power) : power(power), type(type) {}

int Cell::getPower() {
    return power;
}

std::string Cell::printPower() {
    return type << std::to_string(power);
}


Cell DEF_CELL = Cell();
