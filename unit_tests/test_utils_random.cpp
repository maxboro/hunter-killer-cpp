#include <string>
#include "../external/catch2/catch_amalgamated.hpp"
#include "../include/utils_random.hpp"

TEST_CASE("random_uniform_int output is int", "[random_uniform_int]") {
    int rand_int = random_uniform_int(0, 10);
    std::string value_type = typeid(rand_int).name();
    REQUIRE(value_type == "i");
}

TEST_CASE("random_uniform_int output is in interval", "[random_uniform_int]") {
    for (int i = 0; i < 20; i++){
        int rand_int = random_uniform_int(0, 10);
        REQUIRE((rand_int >= 0 && rand_int <= 10));
    }
}
