#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <unordered_set>
#include <sstream>
#include <ostream>
#include "../include/location.hpp"
#include "../include/utils_random.hpp"

enum Move { Up, Down, Left, Right, Pass };

// game agent base class
class Player {
public:
    Player(std::string name, Location location): 
        _name(name), _location(location), 
        _is_alive(true), _sign(' ')  {}

    virtual ~Player() = default;

    bool is_alive() const {return _is_alive;}

    Location get_location() const {
        return _location;
    }

    std::string get_name() const {
        return _name;
    }

    char get_sign() const {
        return _sign;
    }

    void kill() {
        if (_is_alive){
            _is_alive = false;
            _sign = 'X';
        } else {
            throw std::runtime_error(_name + " is already dead");
        }
    }

    void move(Move where){
        Location new_potential_location = _location;
        switch (where){
            case Move::Left:
                new_potential_location.update_x(-1);
                break;
            case Move::Right:
                new_potential_location.update_x(1);
                break;
            case Move::Up:
                new_potential_location.update_y(-1);
                break;
            case Move::Down:
                new_potential_location.update_y(1);
                break;
            case Move::Pass:
                break;
        }
        _location = new_potential_location;
    }

    void random_move(){
        Move move_to_exec = static_cast<Move>(random_uniform_int(Move::Up, Move::Pass));
        move(move_to_exec);
    }

    // Overload <<
    friend std::ostream& operator<<(std::ostream& os, const Player& obj) {
        std::string alive_str = (obj._is_alive)? "Alive" : "Dead";
        os << obj._name <<  " at " << obj._location << ". " << alive_str;
        return os;
    }

    // string representation
    std::string to_str() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }

protected:
    std::string _name;
    Location _location;
    bool _is_alive;
    char _sign;
};

class Hunter: public Player {
public:
    Hunter(Location location): Player("Hunter", location) {
        _sign = 'H';
    }
};

class Prey: public Player {
public:
    Prey(std::string name, Location location): Player(name, location) {
        _sign = 'P';
    }
};

#endif
