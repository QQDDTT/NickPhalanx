#include "Step.h"

Step::Step() {
    step = 0;
}

int Step::getStep() {
    return step;
}

void Step::next() {
    step++;
}