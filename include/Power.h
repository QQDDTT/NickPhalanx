#ifndef POWER_H
#define POWER_H

#include <string>
#include <functional>

// 能量类，定义了能量的基本运算

class Power {
    public:
        static const int MAX_POWER = 99;
        Power();
        Power(int power);
        int getPower();
        std::string getStr();
        void operator>>(Power&other);
        void half();
    private:
        int power;
};

#endif // POWER_H