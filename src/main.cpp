#include <iostream>
#include <string>
#include <random>
#include <memory>  // 使用智能指针

#include "View.h"
#include "Phalanx.h"
#include "AliveCell.h"
#include "Position.h"
#include "Control.h"

Phalanx phalanx;

// 生成初始状态
void build() {
    std::cout << "Building..." << std::endl;
    int x0 = 0, y0 = 0, x1 = 9, y1 = 9;

    phalanx = Phalanx(x0, x1, y0, y1);

    std::random_device rd;  // 随机数种子
    std::mt19937 gen(rd()); // 生成器
    std::uniform_int_distribution<int> dist(0, 5);

    for (int x = x0; x <= x1; x++) {
        for (int y = x + 1; y <= y1; y++) {
            int randVal = dist(gen);  // 生成随机数
            std::unique_ptr<Cell> cell = std::make_unique<Cell>(WHITE, randVal);

            phalanx.setCell(Position(x, y), cell.get());
            phalanx.setCell(Position(y, x), cell.get());

            // 由于 cell 是智能指针，必须手动释放管理
            cell.release();
        }
    }

    // 创建红色和蓝色活动单元
    std::unique_ptr<Cell> redCell = std::make_unique<AliveCell>(RED, 10);
    phalanx.setCell(Position(x0, y1), redCell.get());
    redCell.release();

    std::unique_ptr<Cell> blueCell = std::make_unique<AliveCell>(BLUE, 10);
    phalanx.setCell(Position(x1, y0), blueCell.get());
    blueCell.release();

    std::cout << "Completed" << std::endl;
}

Control redControl = Control(RED);
Control blueControl = Control(BLUE);

// 主函数
int main() {
    std::cout << "Start" << std::endl;

    build();
    for (int i = 0; i < 10; i++) {
        redControl << phalanx;
        blueControl << phalanx;
        phalanx.nextStep();
    }

    view << phalanx;
    std::cout << "End" << std::endl;
    return 0;
}
