#include "Step.h"

// 构造函数
Step::Step() : step(0) {}

// 获取当前回合
int Step::getStep() {
    return step;
}

// 进行下一回合
void Step::next() {
    step++;
}