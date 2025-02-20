#ifndef STEP_H
#define STEP_H

// 回合类，用于记录回合数

class Step {
    public:
        Step();
        int getStep();
        void next();
    private:
        int step;
};

#endif // STEP_H