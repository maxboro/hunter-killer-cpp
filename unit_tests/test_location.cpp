#include "../external/catch2/catch_amalgamated.hpp"
#include "../include/location.hpp"

TEST_CASE("Location creation", "[Location]") {
    int x = 1;
    int y = 2;
    Location loc1 = Location(x, y);
    REQUIRE(loc1.get_x() == x);
    REQUIRE(loc1.get_y() == y);
}

TEST_CASE("Location equality operator: equality", "[Location]") {
    Location loc1 = Location(1, 2);
    Location loc2 = Location(1, 2);
    REQUIRE(loc1 == loc2);
}

TEST_CASE("Location equality operator: inequality", "[Location]") {
    Location loc1 = Location(1, 2);
    Location loc2 = Location(2, 2);
    REQUIRE_FALSE(loc1 == loc2);
}

TEST_CASE("Location inequality operator: equality", "[Location]") {
    Location loc1 = Location(1, 2);
    Location loc2 = Location(1, 2);
    REQUIRE_FALSE(loc1 != loc2);
}

TEST_CASE("Location inequality operator: inequality", "[Location]") {
    Location loc1 = Location(1, 2);
    Location loc2 = Location(2, 2);
    REQUIRE(loc1 != loc2);
}

TEST_CASE("Location string representation", "[Location]") {
    Location loc1 = Location(1, 2);
    std::string loc1_repr = loc1.to_str();
    REQUIRE(loc1_repr == "Loc[1; 2]");
}
