#include "Type.h"
#include <string>
#include <iostream>

// 构造函数
Type::Type() : name(""), color(BLACK_) {}

// Linux 和 macOS
#if defined(__linux__) || defined(__APPLE__)

// 构造函数
Type::Type(std::string name, std::string color) : name(name), color(color) {}

std::string Type::getColor() const {
    return color;
}

#endif

// Windows
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

// 构造函数
Type::Type(std::string name, int color) : name(name), color(color) {}

int Type::getColor() const {
    return color;
}

#endif

bool Type::operator==(const Type& type) {
    return name == type.getName();
}

// 获取名称
std::string Type::getName() const {
    return name;
}

Type BLACK = Type("BLACK", BLACK_);
Type WHITE = Type("WHITE", WHITE_);
Type RED = Type("RED", RED_);
Type BLUE = Type("BLUE", BLUE_);