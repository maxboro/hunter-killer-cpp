#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <unordered_set>
#include "../include/location.hpp"

class Player {
public:
    Player(std::string name, Location location): _name(name), _location(location) {
        _is_alive = true;
        _possible_moves = {"left", "right", "up", "down", "pass"};
    };

    bool is_alive() const {return _is_alive;}

    void move(std::string where){
        if (!_possible_moves.contains(where)){
            throw std::runtime_error("Wrong move: " + where);
        }
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
