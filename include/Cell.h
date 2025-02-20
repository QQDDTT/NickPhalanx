#ifndef CELL_H
#define CELL_H

#include "Type.h"
#include "Power.h"
#include "Position.h"  
#include <string>

// 单元类型，表示一个格子
class Cell {
    public:

        Cell ();
        Cell (Type type, int power);
        virtual ~Cell () = default; // 析构函数，用于释放内存
        Power& getPower();
        int showPower();
        void printPower();
        Type& getType();
        std::string showType();
    protected:
        Power power; // 能量
        Type type; // 类型
};

extern Cell DEF; // 默认单元

#endif // CELL_H