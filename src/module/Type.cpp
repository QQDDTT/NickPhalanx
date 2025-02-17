#include "Type.h"
#include <string>
#include <iostream>

Type::Type() : name(""), color(BLACK_) {}

#if defined(__linux__) || defined(__APPLE__)

Type::Type(std::string name, std::string color) : name(name), color(color) {}

void Type::operator<<(std::string text) {
    std::cout << color << text << RESET_;
}


#endif

#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>

Type::Type(std::string name, int color) : name(name), color(color) {}

void Type::setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Type::operator<<(std::string text) {
    setColor(color);
    std::cout << text;
    setColor(RESET_);
}

#endif



Type BLACK = Type("DEF", BLACK_);
Type WHITE = Type("ALIVE", WHITE_);
Type RED = Type("RED", RED_);
Type BLUE = Type("BLUE", BLUE_);