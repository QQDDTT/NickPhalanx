#include "Cell.h"
#include "Type.h"

// 默认构造函数
Cell::Cell() : power(Power(0)), type(BLACK) {}

// 自定义构造函数
Cell::Cell(Type type, int power) : power(Power(power)), type(type) {}

// 获取单元的能量数
int Cell::showPower() {
    return power.getPower();
}

// 获取单元的能量
Power& Cell::getPower() {
    return power;
}

// 获取单元的类型
Type& Cell::getType() {
    return type;
}

// 打印单元的类型
std::string Cell::showType() {
    return type.getName();
}

// 默认单元
Cell DEF = Cell(WHITE, 0);
