#include "AliveCell.h"

// 构造函数
AliveCell::AliveCell() : Cell(WHITE, 1) {
    this->action = 0;
}

// 构造函数
AliveCell::AliveCell(Type type, int power) : Cell(type, power) {
    this->action = 0;
}

// 复制构造函数
AliveCell::AliveCell(Cell&cell) : Cell(cell.getType(), cell.showPower()) {
    this->action = 0;
}

// 重置动作次数
void AliveCell::resetAction() {
    this->action = power.getPower();
}

// 获取动作次数
int AliveCell::getAction() {
    return this->action;
}