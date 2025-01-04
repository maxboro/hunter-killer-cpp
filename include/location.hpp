#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <sstream>
#include <ostream>

class Location{
public:
    int x;
    int y;
    Location(int x, int y): x(x), y(y) {};

    // Overloading ==
    bool operator==(const Location& other) const {
        return this->x == other.x && this->y == other.y;
    }

    // Overload <<
    friend std::ostream& operator<<(std::ostream& os, const Location& obj) const {
        os << "Loc[" << obj.x << "; " << obj.y << "]";
        return os;
    }

    // string representation
    std::string to_str() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
};

#endif
