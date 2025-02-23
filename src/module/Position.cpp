#include "Position.h"

// 构造函数
Position::Position() : x(0), y(0) {}

//  自定义构造函数
Position::Position(int x, int y) : x(x), y(y) {}

// 获取 x 轴坐标
int Position::getX() const {
    return x;
}

// 获取 y 轴坐标
int Position::getY() const {
    return y;
}

// 转换为字符串
std::string Position::toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

// 计算距离
int Position::getMod() {
    int mod = 0;
    mod += x > 0 ? x : -x;
    mod += y > 0 ? y : -y;
    return mod;
}

// 定义加法
Position Position::operator+(const Position position) const {
    return Position(x + position.getX(), y + position.getY());
}

// 定义减法
Position Position::operator-(const Position position) const {
    return Position(x - position.getX(), y - position.getY());
}

// 定义等于
bool Position::operator==(const Position& position) const {
    return x == position.getX() && y == position.getY();
}


const Position UNIT_UP = Position(0, 1);
const Position UNIT_DOWN = Position(0, -1);
const Position UNIT_LEFT = Position(-1, 0);
const Position UNIT_RIGHT = Position(1, 0);