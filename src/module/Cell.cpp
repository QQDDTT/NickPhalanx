#include "Cell.h"

Cell::Cell() : power(Power(0)), type(DEF) {}

Cell::Cell(Type type, int power) : power(Power(0)), type(type) {}

int Cell::getPower() {
    return power.getPower();
}

std::string Cell::printPower() {
    return type << power.getStr();
}


Cell DEF_CELL = Cell();
