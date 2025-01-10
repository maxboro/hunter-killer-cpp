#ifndef PREY_LIST_HPP
#define PREY_LIST_HPP

#include <vector>
#include "player.hpp"

class PreyList {
public:
    PreyList(){
        _prey_list = {};
    }

    void add(const Prey& prey){
        _prey_list.push_back(prey);
    }

    void random_move(){
        for (Prey& prey : _prey_list){
            prey.random_move();
        }
    }

    int get_size() const {
        return _prey_list.size();
    }

private:
    std::vector<Prey> _prey_list;
};

#endif
