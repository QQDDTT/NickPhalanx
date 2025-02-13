#include <iostream>

#include "View.h"
#include "Phalanx.h"
#include "Position.h"
#include "Cell.h"
#include "Type.h"
#include "AliveCell.h"


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
