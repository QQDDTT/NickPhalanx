#include "View.h"
#include "Position.h"
#include "Phalanx.h"

#include <typeinfo>
#include <iostream>

// 构造函数
View::View() {}

// 输出二位空间的信息
void View::operator<<(Phalanx& phalanx) {

    // 输出所有单元的能量矩阵
    std::cout << "PowerMap: " << std::endl;
    for (int y = phalanx.getMinY(); y <= phalanx.getMaxY(); y++) {  // 先 Y 轴
        for (int x = phalanx.getMinX(); x <= phalanx.getMaxX(); x++) {
            auto cell = phalanx.getCell(Position(x, y));  // 避免多次访问
            cell.printPower();
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    // 输出所有活动单元的位置和动作点数
    std::cout << "ActionList: " << std::endl;
    std::unordered_map<Position, Cell*> cells = phalanx.getCells();
    for (auto& cellPair : cells) {
        if (auto* aliveCell = dynamic_cast<AliveCell*>(cellPair.second)) {
            std::cout << "Found AliveCell at " << cellPair.first.toString();
            std::cout << " Action: ";
            aliveCell->printAction();
            std::cout << std::endl;
        }
    }
}

// 输出单元的信息
void View::operator<<(Cell& cell) {
    // 如果是活动单元，输出动作点
    if (typeid(cell) == typeid(AliveCell)) {
        std::cout << "Action: ";
        AliveCell aliveCell(cell);
        aliveCell.printAction();
    }
    // 输出单元的能量
    std::cout << "Power: ";
    cell.printPower();
    std::cout << std::endl;
}

// 输出位置的信息
void View::operator<<(Position& position) {
    std::cout << position.getX() << " " << position.getY();
}

View view = View();