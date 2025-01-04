#include "../external/catch2/catch_amalgamated.hpp"
#include "../include/player.hpp"
#include "../include/location.hpp"

TEST_CASE("Hunter creation", "[Hunter]") {
    std::string name = "hunter";
    Location loc1 = Location(1, 1);
    Hunter hunter = Hunter(name, loc1);
    REQUIRE(hunter.is_alive());
}

TEST_CASE("Prey creation", "[Prey]") {
    std::string name = "Prey";
    Location loc1 = Location(1, 1);
    Prey prey = Prey(name, loc1);
    REQUIRE(prey.is_alive());
}

TEST_CASE("Hunter wrong move", "[Hunter]") {
    std::string name = "hunter";
    Location loc1 = Location(1, 1);
    Hunter hunter = Hunter(name, loc1);
    REQUIRE_THROWS(hunter.move("upp"));
}

TEST_CASE("Hunter allowed move", "[Hunter]") {
    std::string name = "hunter";
    Location loc1 = Location(1, 1);
    Hunter hunter = Hunter(name, loc1);
    REQUIRE_NOTHROW(hunter.move("up"));
}
