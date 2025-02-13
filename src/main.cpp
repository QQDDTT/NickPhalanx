#include <iostream>

#include "View.h"
#include "Phalanx.h"
#include "AliveCell.h"
#include "Position.h"
#include "View.h"

int main() {
    std::cout << "Start" << std::endl;

    Phalanx phalanx;
    phalanx = Phalanx();
    AliveCell redCell = AliveCell(RED, 1);
    phalanx.setCell(Position(0, 0), redCell);
    view << phalanx;

    std::cout << "End" << std::endl;
    return 0;
}