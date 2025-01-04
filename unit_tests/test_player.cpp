#include "../external/catch2/catch_amalgamated.hpp"
#include "../include/player.hpp"
#include "../include/location.hpp"

TEST_CASE("Hunter creation", "[Hunter]") {
    std::string name = "hunter";
    Location loc1 = Location(1, 1);
    // Player hunter = Player(name, loc1);
    Hunter hunter = Hunter(name, loc1);
    REQUIRE(hunter.is_alive());
}

TEST_CASE("Prey creation", "[Prey]") {
    std::string name = "Prey";
    Location loc1 = Location(1, 1);
    // Player prey = Player(name, loc1);
    Prey prey = Prey(name, loc1);
    REQUIRE(prey.is_alive());
}
