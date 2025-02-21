#include "Type.h"
#include "Position.h"
#include "Phalanx.h"
#include "Cell.h"

#include <typeinfo>

// 默认构造函数
Phalanx::Phalanx() : Phalanx(0, 9, 0, 9) {}

// 自定义构造函数
Phalanx::Phalanx(int min_x, int max_x, int min_y, int max_y)
    : min_x(min_x), max_x(max_x), min_y(min_y), max_y(max_y) {
    cells = std::unordered_map<Position, Cell*>();
    for (int x = min_x; x <= max_x; x++) {
        for (int y = min_y; y <= max_y; y++) {
            cells[Position(x, y)] = &DEF;
        }
    }
}

// 获取指定位置的单元
Cell* Phalanx::getCell(Position position) {
    return cells[position];
}

// 设置指定位置的单元
void Phalanx::setCell(Position position, Cell* cell) {
    cells[position] = cell;
}

// 获取所有单元
std::unordered_map<Position, Cell*> Phalanx::getCells() {
    return cells;
}

// 获取二元空间的边界
int Phalanx::getMinX() { return min_x; }
int Phalanx::getMaxX() { return max_x; }
int Phalanx::getMinY() { return min_y; }
int Phalanx::getMaxY() { return max_y; }

// 计算两个位置之间的距离
int Phalanx::getDistance(Position position1, Position position2) {
    return (position1 - position2).getMod();
}

// 进行下一步，重置所有活动单元的动作数
void Phalanx::nextStep() {
    step.next();
    for (auto& cellPair : cells) {
        if (AliveCell* aliveCell = dynamic_cast<AliveCell*>(cellPair.second)) {
            aliveCell->resetAction();
        }
    }
}

// 细胞移动
bool Phalanx::move(Position from, Position to) {
    auto itFrom = cells.find(from);
    auto itTo = cells.find(to);

    if (itFrom == cells.end() || itTo == cells.end()) {
        return false;
    }

    if (AliveCell* aliveCell = dynamic_cast<AliveCell*>(itFrom->second)) {
        if (itTo->second == &DEF) {
            cells[to] = aliveCell;
            cells.erase(itFrom);
            return true;
        }
    }
    return false;
}

// 掠夺
bool Phalanx::plunder(Position from, Position to) {
    auto itFrom = cells.find(from);
    auto itTo = cells.find(to);
    if (itFrom == cells.end() || itTo == cells.end()) {
        return false;
    }

    if (AliveCell* aliveCell = dynamic_cast<AliveCell*>(itFrom->second)) {
        if (aliveCell->showPower() > itTo->second->showPower()) {
            aliveCell->getPower() << itTo->second->getPower();
            if (itTo->second->showPower() == 0) {
                itTo->second = &DEF;
            }
            return true;
        }
    }
    return false;
}

// 贡献
bool Phalanx::dedicate(Position from, Position to) {
    auto itFrom = cells.find(from);
    auto itTo = cells.find(to);
    if (itFrom == cells.end() || itTo == cells.end()) {
        return false;
    }

    if (AliveCell* aliveCell = dynamic_cast<AliveCell*>(itFrom->second)) {
        aliveCell->getPower() >> itTo->second->getPower();
        if (aliveCell->showPower() == 0) {
            itFrom->second = &DEF;
        }
        return true;
    }
    return false;
}
