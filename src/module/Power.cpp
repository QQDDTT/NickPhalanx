#include "Power.h"

Power::Power() : Power(0) {}

Power::Power(int power) {
    if (power > MAX_POWER) {
        power = MAX_POWER;
    } else {
        this->power = power;
    }
}

int Power::getPower() {
    return power;
}

std::string Power::getStr() {
    if (power < 10) {
        return "0" + std::to_string(power);
    }
    return std::to_string(power);
}

void Power::operator>>(Power power) {
    if (this->power > 0) {
        this->power--;
        power.power++;
    }
}

void Power::operator<<(Power power) {
    if (this->power > power.power) {
        this->power++;
        power.power--;
    }
}