#ifndef TYPE_H
#define TYPE_H

#include "Color.h"
#include <string>

class Type{
    public:
        Type();
        Type(std::string name, std::string color_text);
        std::string operator<<(std::string text);
    private:
        std::string name;
        std::string color_text;
};


extern Type BLACK;
extern Type WHITE;
extern Type RED;
extern Type BLUE;

#endif // TYPE_H