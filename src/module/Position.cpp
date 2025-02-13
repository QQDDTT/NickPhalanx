#include "Position.h"

Position::Position() : x(0), y(0) {}

Position::Position(int x, int y) : x(x), y(y) {}

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

std::string Position::toString() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

int Position::getMod() {
    int mod = 0;
    mod += x > 0 ? x : -x;
    mod += y > 0 ? y : -y;
    return mod;
}

Position Position::operator+(Position position) {
    return Position(x + position.getX(), y + position.getY());
}

Position Position::operator-(Position position) {
    return Position(x - position.getX(), y - position.getY());
}

bool Position::operator==(const Position& position) const {
    return x == position.getX() && y == position.getY();
}
