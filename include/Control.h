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

// 控制类，用于控制单元

class Control {
    public:
        Control(Type type);
        
        void operator<<(Phalanx &phalanx);
        
    private:
        Type type; // 控制的类型，表示玩家的阵营
        std::unordered_map<Position, AliveCell> aliveCells; // 存储本类型的活动单元
};

#endif // CONTROL_H