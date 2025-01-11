#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "game.hpp"

class Manager{
public:
    Manager(Game& game, Settings* settings): 
        _game(game),  
        _settings(settings){};

    void run_game(){
        _add_prey();

        // game loop
        const int n_steps = _settings->get_value("n_steps");
        for (int i = 0; i < n_steps; i++){
            _game.make_move();
            _game.show_status();
        }
    }

private:
    Game _game;
    Settings* _settings;

    void _add_prey(){
        const int n_prey = _settings->get_value("n_prey");
        for (int prey_id = 0; prey_id < n_prey; prey_id++){
            std::string prey_name = "Prey_" + std::to_string(prey_id);
            _game.add_prey(prey_name);
        }
    }
};

#endif