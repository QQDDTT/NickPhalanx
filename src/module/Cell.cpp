#include "Cell.h"
#include "Type.h"

Cell Cell::DEF() {
    return Cell(WHITE, 0);
}

Cell::Cell() : power(Power(0)), type(BLACK) {}

Cell::Cell(Type type, int power) : power(Power(power)), type(type) {}

int Cell::getPower() {
    return power.getPower();
}

std::string Cell::printPower() {
    return type << power.getStr();
}


