#ifndef POWER_H
#define POWER_H

#include <string>
#include <functional>

class Power {
    public:
        static const int MAX_POWER = 99;
        Power();
        Power(int power);
        int getPower();
        std::string getStr();
        void operator>>(Power power);
        void operator<<(Power power);
    private:
        int power;
}

#endif // POWER_H