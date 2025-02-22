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

int Phalanx::getStep() {
    return step.getStep();
}

// 获取所有单元
std::unordered_map<Position, Cell*> Phalanx::getCells() {
    return cells;
}

// 获取所有活动单元
std::unordered_map<Position, AliveCell*> Phalanx::getAliveCells() {
    std::unordered_map<Position, AliveCell*> aliveCells;
    for (auto& cellPair : cells) {
        if (AliveCell* aliveCell = dynamic_cast<AliveCell*>(cellPair.second)) {
            aliveCells[cellPair.first] = aliveCell;
        }
    }
    return aliveCells;
}

// 获取相邻的单元
std::unordered_map<Position, Cell*> Phalanx::getNeighors(Position position) {
    std::unordered_map<Position, Cell*> neighors;
    Position up = position + UNIT_UP;
    Position down = position + UNIT_DOWN;
    Position left = position + UNIT_LEFT;
    Position right = position + UNIT_RIGHT;
    if (cells.find(up) != cells.end()) {
        neighors[up] = cells[up];
    }
    if (cells.find(down) != cells.end()) {
        neighors[down] = cells[down];
    }
    if (cells.find(left) != cells.end()) {
        neighors[left] = cells[left];
    }
    if (cells.find(right) != cells.end()) {
        neighors[right] = cells[right];
    }
    return neighors;
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

// 移动
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
            std::cout << "Move from " << from.toString() << " to " << to.toString() << std::endl;
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
        aliveCell->getAction();
        if (aliveCell->showPower() > itTo->second->showPower() && itTo->second->showPower() > 0) {
            itTo->second->getPower() >> aliveCell->getPower();
            if (itTo->second->showPower() == 0) {
                itTo->second = &DEF;
            }
            std::cout << "Plunder from " << from.toString() << " to " << to.toString() << std::endl;
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
        std::cout << "Dedicate from " << from.toString() << " to " << to.toString() << std::endl;
        return true;
    }
    return false;
}

// 复制
bool Phalanx::copy(Position from, Position to) {
    auto itFrom = cells.find(from);
    auto itTo = cells.find(to);
    if (itFrom == cells.end() || itTo == cells.end()) {
        return false;
    }

    if (AliveCell* aliveCell = dynamic_cast<AliveCell*>(itFrom->second)) {
        if (itTo->second->showPower() == 0 && aliveCell->showPower() >= 10) {
            Cell* newCell = new AliveCell(aliveCell->getType(), aliveCell->showPower() / 2);
            cells[to] = new AliveCell(*newCell);
            aliveCell->getPower().half();
            std::cout << "Copy from " << from.toString() << " to " << to.toString() << std::endl;
            return true;
        }
    }
    return false;
}
