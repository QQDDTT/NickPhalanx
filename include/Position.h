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
        Position operator+(Position position);
        Position operator-(Position position);
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

#endif // POSITION_H