#include "Power.h"

// 构造函数
Power::Power() : Power(0) {}

// 构造函数
Power::Power(int power) {
    if (power > MAX_POWER) {
        power = MAX_POWER;
    } else {
        this->power = power;
    }
}

// 获取能量
int Power::getPower() {
    return power;
}

// 转换为字符串，打印为00-99
std::string Power::getStr() {
    if (power < 10) {
        return "0" + std::to_string(power);
    }
    return std::to_string(power);
}

// 能量运算
void Power::operator>>(Power&other) {
    if (this->power > 0) {
        --power;
        ++other.power;
    }
}

void Power::half() {
    if (power % 2 == 1) {
        ++power;
    }
    power /= 2;
}