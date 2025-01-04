#include "../external/catch2/catch_amalgamated.hpp"
#include "../include/player.hpp"
#include "../include/location.hpp"

TEST_CASE("Hunter creation", "[Hunter]") {
    std::string name = "hunter";
    Location loc = Location(1, 1);
    Hunter hunter = Hunter(name, loc);
    REQUIRE(hunter.is_alive());
}

TEST_CASE("Prey creation", "[Prey]") {
    std::string name = "Prey";
    Location loc = Location(1, 1);
    Prey prey = Prey(name, loc);
    REQUIRE(prey.is_alive());
}

TEST_CASE("Hunter allowed move", "[Hunter]") {
    std::string name = "hunter";
    Location loc = Location(1, 1);
    Hunter hunter = Hunter(name, loc);
    REQUIRE_NOTHROW(hunter.move(Up));

    Location loc_new = hunter.get_location();
    REQUIRE(loc_new.get_x() == 1);
    REQUIRE(loc_new.get_y() == 0);
}

TEST_CASE("Hunter random move", "[Hunter]") {
    std::string name = "hunter";
    Location loc = Location(1, 1);
    Hunter hunter = Hunter(name, loc);
    REQUIRE_NOTHROW(hunter.random_move());
}
