#ifndef MAIN_HPP
#define MAIN_HPP

#include "Settings.hpp"

int main(){
    // Settings
    Settings* settings = Settings::get_instance();
    settings->load_settings();

    std::cout << "n_prey: " << settings->get_value("n_prey") << std::endl;
    return 0;
}

#endif
