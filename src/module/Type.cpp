#include "Type.h"
#include <string>
#include <iostream>

// 构造函数
Type::Type() : name(""), color(BLACK_) {}

// Linux 和 macOS
#if defined(__linux__) || defined(__APPLE__)

// 构造函数
Type::Type(std::string name, std::string color) : name(name), color(color) {}

// 输出函数
void Type::operator<<(std::string text) {
    std::cout << color << text << RESET_;
}

#endif

// Windows
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

// 构造函数
Type::Type(std::string name, int color) : name(name), color(color) {}

// 设置颜色
void Type::setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 输出函数
void Type::operator<<(std::string text) {
    setColor(color);
    std::cout << text;
    setColor(RESET_);
}

#endif

// 获取名称
std::string Type::getName() {
    return name;
}

Type BLACK = Type("DEF", BLACK_);
Type WHITE = Type("ALIVE", WHITE_);
Type RED = Type("RED", RED_);
Type BLUE = Type("BLUE", BLUE_);