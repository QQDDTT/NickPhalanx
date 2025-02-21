#ifndef TYPE_H
#define TYPE_H

#include <string>

// TYPE类，用于表示不同类型的单元

// Linux 和 macOS
#if defined(__linux__) || defined(__APPLE__)
class Type {
    public:
        Type();
        Type(std::string name, std::string color);
        bool operator==(const Type& type);
        std::string getName() const;
        std::string getColor() const;
        
    private:
        std::string name;
        std::string color;
};

// 颜色常量
const std::string BLACK_ = "\033[30m";
const std::string WHITE_ = "\033[37m";
const std::string RED_   = "\033[31m";
const std::string BLUE_  = "\033[34m";
const std::string RESET_ = "\033[0m";

#endif


// Windows
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

class Type {
    public:
        static void setColor(int color);
        Type();
        Type(std::string name, int color);
        bool operator==(const Type& type);
        std::string getName() const;
        int getColor() const;
        
    private:
        std::string name;
        int color;
};

// Windows 控制台颜色代码
constexpr int BLACK_ = 0;
constexpr int WHITE_ = 7;
constexpr int RED_   = 4;
constexpr int BLUE_  = 9;
constexpr int RESET_ = 7;

#endif

// 全局对象
extern Type BLACK;
extern Type WHITE;
extern Type RED;
extern Type BLUE;

#endif // TYPE_H
