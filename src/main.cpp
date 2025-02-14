#include <iostream>
#include <string>
#include <random>

#include "View.h"
#include "Phalanx.h"
#include "AliveCell.h"
#include "Position.h"
#include "View.h"

Phalanx phalanx;

void build () {
    std::cout << "building.." << std::endl;
    int x0, y0, x1, y1;
    x0 = 0;
    y0 = 0;
    x1 = 9;
    y1 = 9;

    phalanx = Phalanx(x0, x1, y0, y1);
    for (int x = x0; x <= x1; x++) {
        for (int y = x + 1; y <= y1; y++) {

            std::random_device rd;  // 随机种子
            std::mt19937 gen(rd()); // 生成器
            std::uniform_int_distribution<int> dist(0, 5);
            int rand = dist(gen);  // 生成随机数

            Cell cell = Cell(WHITE, rand);
            phalanx.setCell(Position(x, y), cell);
            phalanx.setCell(Position(y, x), cell);
        }
    }

    AliveCell redCell = AliveCell(RED, 10);
    phalanx.setCell(Position(x0, y1), redCell);

    AliveCell blueCell = AliveCell(BLUE, 10);
    phalanx.setCell(Position(x1, y0), blueCell);

    std::cout << "complish" << std::endl;
}


int main() {
    std::cout << "Start" << std::endl;

    build();

    view << phalanx;

    std::cout << "End" << std::endl;
    return 0;
}