#include "Control.h"
#include "Phalanx.h"
#include "Position.h"


// 构造函数
Control::Control(Type type) : type(type) {}

// 导入活动单元
bool Control::operator<<(Phalanx &phalanx) {
    bool result = false;
    std::unordered_map<Position, AliveCell*> aliveCells = phalanx.getAliveCells();
    for (auto& cellPair : aliveCells) {
        if (cellPair.second->getType() == type) {
            result = true;
            std::unordered_map<Position, Cell*> neighors = phalanx.getNeighors(cellPair.first);
            for (auto& neighorPair : neighors) {
                // building...
            }
            for (int i = 0; i < cellPair.second->getAction(); i++) {
                std::random_device rd;  // 随机数种子
                std::mt19937 gen(rd()); // 生成器
                std::uniform_int_distribution<int> dist(0, 12);
                int randVal = dist(gen);  // 生成随机数
    
                switch (randVal)
                {
                case 1:
                    phalanx.move(cellPair.first, cellPair.first + UNIT_UP);
                    break;
                case 2:
                    phalanx.move(cellPair.first, cellPair.first + UNIT_DOWN);
                    break;    
                case 3:
                    phalanx.move(cellPair.first, cellPair.first + UNIT_LEFT);
                    break;
                case 4:
                    phalanx.move(cellPair.first, cellPair.first + UNIT_RIGHT);
                    break;
                case 5:
                    phalanx.plunder(cellPair.first, cellPair.first + UNIT_UP);
                    break;
                case 6:
                    phalanx.plunder(cellPair.first, cellPair.first + UNIT_DOWN);
                    break;    
                case 7:
                    phalanx.plunder(cellPair.first, cellPair.first + UNIT_LEFT);
                    break;
                case 8:
                    phalanx.plunder(cellPair.first, cellPair.first + UNIT_RIGHT);
                    break;
                case 9:
                    phalanx.copy(cellPair.first, cellPair.first + UNIT_UP);
                    break;
                case 10:
                    phalanx.copy(cellPair.first, cellPair.first + UNIT_DOWN);
                    break;
                case 11:
                    phalanx.copy(cellPair.first, cellPair.first + UNIT_LEFT);
                    break;
                case 12:
                    phalanx.copy(cellPair.first, cellPair.first + UNIT_RIGHT);
                    break;
                default:
                    std::cout << "Waiting..." << std::endl;
                    break;
                }
            }
        }
    }
    return result;
}
