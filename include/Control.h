#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <random>

#include "View.h"
#include "Phalanx.h"
#include "AliveCell.h"
#include "Position.h"
#include "Cell.h"
#include "Type.h"

class Control {
    public:
        Control(Type type);
        
        void operator<<(Phalanx &phalanx);
        
    private:
        Type type;
        std::unordered_map<Position, AliveCell> aliveCells;


};

#endif // CONTROL_H