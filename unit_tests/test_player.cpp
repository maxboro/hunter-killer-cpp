#include "../external/catch2/catch_amalgamated.hpp"
#include "../include/player.hpp"
#include "../include/location.hpp"

TEST_CASE("Hunter creation and kill", "[Hunter]") {
    Location loc = Location(1, 1);
    Hunter hunter = Hunter(loc);
    REQUIRE(hunter.is_alive());
    REQUIRE(hunter.get_sign() == 'H');

    REQUIRE(hunter.to_str() == "Hunter at Loc[1; 1]. Alive");

    hunter.kill();
    REQUIRE(hunter.get_sign() == 'X');
    REQUIRE(hunter.to_str() == "Hunter at Loc[1; 1]. Dead");

    REQUIRE_THROWS_AS(hunter.kill(), std::runtime_error);
}

TEST_CASE("Prey creation and kill", "[Prey]") {
    std::string name = "Prey";
    Location loc = Location(1, 1);
    Prey prey = Prey(name, loc);
    REQUIRE(prey.is_alive());
    REQUIRE(prey.get_sign() == 'P');

    REQUIRE(prey.to_str() == "Prey at Loc[1; 1]. Alive");

    prey.kill();
    REQUIRE(prey.get_sign() == 'X');
    REQUIRE(prey.to_str() == "Prey at Loc[1; 1]. Dead");

    REQUIRE_THROWS_AS(prey.kill(), std::runtime_error);
}

TEST_CASE("Hunter allowed move", "[Hunter]") {
    Location loc = Location(1, 1);
    Hunter hunter = Hunter(loc);
    REQUIRE_NOTHROW(hunter.move(Move::Up));

    Location loc_new = hunter.get_location();
    REQUIRE(loc_new.get_x() == 1);
    REQUIRE(loc_new.get_y() == 0);
}

TEST_CASE("Hunter random move", "[Hunter]") {
    Location loc = Location(1, 1);
    Hunter hunter = Hunter(loc);
    REQUIRE_NOTHROW(hunter.random_move());
}

TEST_CASE("Hunter name get", "[Hunter]") {
    Location loc = Location(1, 1);
    Hunter hunter = Hunter(loc);
    std::string name_get = hunter.get_name();
    REQUIRE(name_get == "Hunter");
}
