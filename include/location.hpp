#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <sstream>
#include <ostream>

class Location{
public:
    Location(int x, int y): _x(x), _y(y) {};

    int get_x() const {return _x;}
    int get_y() const {return _y;}

    void update_x(int increment){_x += increment;}
    void update_y(int increment){_y += increment;}

    // Overloading ==
    bool operator==(const Location& other) const {
        return _x == other.get_x() && _y == other.get_y();
    }

    // Overloading !=
    bool operator!=(const Location& other) const {
        return !(*this == other);
    }

    // Overload <<
    friend std::ostream& operator<<(std::ostream& os, const Location& obj) {
        os << "Loc[" << obj._x << "; " << obj._y << "]";
        return os;
    }

    // string representation
    std::string to_str() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }

private:
    int _x;
    int _y;
};

#endif
