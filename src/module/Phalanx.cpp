#include "Type.h"
#include "Position.h"
#include "Phalanx.h"
#include "Cell.h"

#include <typeinfo>

// 默认构造函数
Phalanx::Phalanx() : min_x(0), max_x(9), min_y(0), max_y(9) {
    Phalanx(0, 9, 0, 9);
}

// 自定义构造函数
Phalanx::Phalanx(int min_x, int max_x, int min_y, int max_y) : min_x(min_x), max_x(max_x), min_y(min_y), max_y(max_y) {
    cells = std::unordered_map<Position, Cell*>();
    for (int x = min_x; x <= max_x; x++) {
        for (int y = min_y; y <= max_y; y++) {
            cells[Position(x, y)] = &DEF;
        }
    }
}

// 获取指定位置的单元
Cell Phalanx::getCell(Position position) {
    return *cells[position];
}

// 设置指定位置的单元
void Phalanx::setCell(Position position, Cell* cell) {
    cells[position] = cell;
}

// 获取所有单元
std::unordered_map<Position, Cell*> Phalanx::getCells() {
    return cells;
}

// 获取二元空间的边界，x 轴最小值
int Phalanx::getMinX() {
    return min_x;
}

// 获取二元空间的边界，x 轴最大值
int Phalanx::getMaxX() {
    return max_x;
}

// 获取二元空间的边界，y 轴最小值
int Phalanx::getMinY() {
    return min_y;
}

// 获取二元空间的边界，y 轴最大值
int Phalanx::getMaxY() {
    return max_y;
}

// 计算两个位置之间的距离
int Phalanx::getDistance(Position position1, Position position2) {
    return (position1 - position2).getMod();
}

// 进行下一步，重置所有活动单元的动作数
void Phalanx::nextStep() {
    step.next();
    for (auto& cellPair : cells) {
        if (typeid(cellPair.second) == typeid(AliveCell)) {
            AliveCell aliveCell(*cellPair.second);
            aliveCell.resetAction();
        }
    }
}
