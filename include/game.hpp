#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include "grid.hpp"
#include "utils_random.hpp"
#include "location.hpp"
#include "prey_list.hpp"
#include "player.hpp"
#include "settings.hpp"

class Game {
public:
    Game(Settings* settings): 
        _settings(settings),
        _grid(Grid(_settings->get_value("grid_size_x"), _settings->get_value("grid_size_y"))),
        _hunter(random_location_on_grid()) {
           _prey_list = PreyList();
           _to_show_grid = _settings->get_value("show_grid");
        };
    
    Location random_location_on_grid() {
        const int coord_x = random_uniform_int(0, _settings->get_value("grid_size_x") - 1);
        const int coord_y = random_uniform_int(0, _settings->get_value("grid_size_y") - 1);
        Location random_location = Location(coord_x, coord_y);
        return random_location;
    }

    void add_prey(std::string prey_name){
        Location random_location = random_location_on_grid();
        Prey new_prey = Prey(prey_name, random_location);
        _prey_list.add(new_prey);
    }

    void show_status() const {
        for (const Prey& prey : _prey_list){
            std::cout << prey << std::endl;
        }

        std::cout << _hunter << std::endl;

        if (_to_show_grid){
            _show_grid();
        }
    }

    void make_move(){
        _prey_list.random_move();
        _hunter.random_move();
        _perform_killings();
    }

private:
    Settings* _settings;
    bool _to_show_grid;
    Grid _grid;
    PreyList _prey_list;
    Hunter _hunter;

    void _show_grid() const {
        Grid populated_grid = _grid;

        // prey
        for (const Prey& prey : _prey_list){
            char sign = prey.get_sign();
            Location loc = prey.get_location();
            populated_grid.set_cell_value(loc.get_x(), loc.get_y(), sign);
        }

        // hunter
        char sign = _hunter.get_sign();
        Location loc = _hunter.get_location();
        populated_grid.set_cell_value(loc.get_x(), loc.get_y(), sign);

        populated_grid.show_grid();
    }

    // Kill prey if possible
    void _perform_killings(){
        Location hunter_current_location = _hunter.get_location();
        for (Prey& prey : _prey_list){
            if (prey.get_location() == hunter_current_location && prey.is_alive()){
                prey.kill();
                std::cout << prey.get_name() << " is killed." << std::endl;
            }
        }
    }
};

#endif
