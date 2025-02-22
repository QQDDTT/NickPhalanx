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
    if (showPower() > 50) {
        this->action = 5;
    } else if (showPower() > 20) {
        this->action = 4;
    } else if (showPower() > 10) {
        this->action = 3;
    } else if (showPower() > 5) {
        this->action = 2;
    } else {
        this->action = 1;
    }
}

// 减少动作次数
void AliveCell::cutAction() {
    if (this->action > 0) {
        --action;
    }
}

// 获取动作次数
int AliveCell::getAction() {
    return this->action;
}