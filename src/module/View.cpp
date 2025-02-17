#include "View.h"
#include "Position.h"
#include "Phalanx.h"

View::View() {}

void View::operator<<(Phalanx& phalanx) {
    for (int y = phalanx.getMinY(); y <= phalanx.getMaxY(); y++) {  // 先 Y 轴
        for (int x = phalanx.getMinX(); x <= phalanx.getMaxX(); x++) {
            auto cell = phalanx.getCell(Position(x, y));  // 避免多次访问
            cell.printPower();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}


View view = View();