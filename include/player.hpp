#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <unordered_set>
#include "../include/location.hpp"

enum Move { Up, Down, Left, Right, Pass };

class Player {
public:
    Player(std::string name, Location location): _name(name), _location(location) {
        _is_alive = true;
    };

    bool is_alive() const {return _is_alive;}

    Location get_location() const {
        return _location;
    }

    void move(Move where){
        Location new_potential_location = _location;
        switch (where){
            case Left:
                new_potential_location.update_x(-1);
                break;
            case Right:
                new_potential_location.update_x(1);
                break;
            case Up:
                new_potential_location.update_y(-1);
                break;
            case Down:
                new_potential_location.update_y(1);
                break;
            case Pass:
                break;
        }
        _location = new_potential_location;
    }

protected:
    std::string _name;
    Location _location;
    bool _is_alive;
    char sign;
    std::unordered_set<std::string> _possible_moves;
    // _moves;
};

class Hunter: public Player {
public:
    Hunter(std::string name, Location location): Player(name, location) {};
};

class Prey: public Player {
public:
    Prey(std::string name, Location location): Player(name, location) {};
};

#endif
