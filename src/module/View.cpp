#include "View.h"
#include "Position.h"
#include "Phalanx.h"

#include <typeinfo>
#include <iostream>

// 构造函数
View::View() {}

// Linux 和 macOS
#if defined(__linux__) || defined(__APPLE__)

// 输出二位空间的信息
void View::operator<<(Phalanx& phalanx) {
    std::cout << "PowerMap: " << std::endl;
    for (int y = phalanx.getMinY(); y <= phalanx.getMaxY(); y++) {
        for (int x = phalanx.getMinX(); x <= phalanx.getMaxX(); x++) {
            auto cell = phalanx.getCell(Position(x, y));
            std::cout << cell->getType().getColor() << cell->getPower().getStr() << RESET_ << " ";
        }
        std::cout << std::endl;
    }
}

#endif

// Windows
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

// 输出二位空间的信息
void View::operator<<(Phalanx& phalanx) {
    std::cout << "PowerMap: " << std::endl;
    for (int y = phalanx.getMinY(); y <= phalanx.getMaxY(); y++) {
        for (int x = phalanx.getMinX(); x <= phalanx.getMaxX(); x++) {
            auto cell = phalanx.getCell(Position(x, y));
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cell->getType().getColor());
            std::cout << cell->getPower().getStr() << " ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE_);
        }
        std::cout << std::endl;
    }
}

#endif


// 输出单元的信息
void View::operator<<(Cell& cell) {
    if (auto* aliveCell = dynamic_cast<AliveCell*>(&cell)) {
        std::cout << " Action: " << aliveCell->getAction();
    }

    std::cout << "Power: " << cell.getPower().getStr();
}


View view = View();
