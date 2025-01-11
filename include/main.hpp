#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include "settings.hpp"
#include "grid.hpp"
#include "game.hpp"
#include "manager.hpp"

int main(){
    Settings* settings = Settings::get_instance();
    settings->load_settings();

    Game game = Game(settings);
    Manager manager = Manager(game, settings);
    manager.run_game();
    return 0;
}

#endif
