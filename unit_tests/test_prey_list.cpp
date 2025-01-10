#include <string>
#include "../external/catch2/catch_amalgamated.hpp"
#include "../include/player.hpp"
#include "../include/prey_list.hpp"


TEST_CASE("PreyList creation", "[PreyList]") {
    REQUIRE_NOTHROW(PreyList());
}

TEST_CASE("PreyList add", "[PreyList]") {
    Location loc = Location(1, 1);
    std::string name = "Prey_1";
    Prey prey = Prey(name, loc);
    PreyList prey_list = PreyList();
    REQUIRE_NOTHROW(prey_list.add(prey));
    REQUIRE(prey_list.get_size() == 1);
}

TEST_CASE("PreyList random move", "[PreyList]") {
    Location loc = Location(1, 1);
    std::string name = "Prey_1";
    Prey prey = Prey(name, loc);
    PreyList prey_list = PreyList();
    prey_list.add(prey);
    REQUIRE_NOTHROW(prey_list.random_move());
}
