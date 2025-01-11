#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <sstream>
#include <ostream>
#include "settings.hpp"

class Location{
public:
    Location(int x, int y): _x(x), _y(y) {
        auto settings = Settings::get_instance();
        _max_x = settings->get_value("grid_size_x") - 1;
        _max_y = settings->get_value("grid_size_y") - 1;
        _min_x = 0;
        _min_y = 0;
    };

    int get_x() const {return _x;}
    int get_y() const {return _y;}

    void update_x(int increment){
        int new_x = _x + increment;
        if (new_x >= _min_x && new_x <= _max_x){
            _x = new_x;
        }
    }

    void update_y(int increment){
        int new_y = _y + increment;
        if (new_y >= _min_y && new_y <= _max_y){
            _y = new_y;
        }
    }

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
    int _min_x;
    int _min_y;
    int _max_x;
    int _max_y;
};

#endif
