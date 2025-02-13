#include "Type.h"
#include "Color.h"
#include <string>


Type::Type() : name(""), color_text(WHITE_) {}

Type::Type(std::string name, std::string ct) : name(name), color_text(ct) {}

std::string Type::operator<<(std::string text) {
    return color_text + text + RESET;
}

Type DEF = Type("DEF", BLACK_);
Type ALIVE = Type("ALIVE", WHITE_);
Type RED = Type("RED", RED_);
Type BLUE = Type("BLUE", BLUE_);