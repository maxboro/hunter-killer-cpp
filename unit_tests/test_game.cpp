#include "../external/catch2/catch_amalgamated.hpp"
#include "../include/game.hpp"
#include "../include/location.hpp"

TEST_CASE("Game creation and show", "[Game]"){
    Settings* settings = Settings::get_instance();
    settings->load_settings();
    
    Game game = Game(settings);
    REQUIRE_NOTHROW(game.add_prey("Prey_1"));
    REQUIRE_NOTHROW(game.make_move());
    REQUIRE_NOTHROW(game.show_status());
}

TEST_CASE("Game random location", "[Game]"){
    Settings* settings = Settings::get_instance();
    settings->load_settings();
    
    Game game = Game(settings);
    Location loc = game.random_location_on_grid();
    REQUIRE_NOTHROW(loc.get_x());
    REQUIRE_NOTHROW(loc.get_y());
}
