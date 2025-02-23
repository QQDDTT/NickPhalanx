#ifndef POSITION_H
#define POSITION_H

#include <string>
#include <functional>

// Position类，用于表示单元在二位空间的位置

class Position {
    public:
        Position();
        Position(int x, int y);
        int getX() const;
        int getY() const;
        int getMod();
        std::string toString() const;
        Position operator+(const Position position) const;
        Position operator-(const Position position) const;
        bool operator==(const Position& position) const;
    private:
        int x, y;
};

// Hash function for Position，用于std::unordered_map检索

namespace std {
    template<> 
    struct hash<Position> {
        std::size_t operator()(const Position& position) const {
            return std::hash<int>()(position.getX()) ^ (std::hash<int>()(position.getY()) << 1);
        }
    };
}

const extern Position UNIT_UP;
const extern Position UNIT_DOWN;
const extern Position UNIT_LEFT;
const extern Position UNIT_RIGHT;

#endif // POSITION_H