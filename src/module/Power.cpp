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

// 能量运算，消耗
void Power::operator>>(Power power) {
    if (this->power > 0) {
        this->power--;
        power.power++;
    }
}

// 能量运算，增加
void Power::operator<<(Power power) {
    if (this->power > power.power) {
        this->power++;
        power.power--;
    }
}