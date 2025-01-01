#define CATCH_CONFIG_MAIN
#include "../external/catch_amalgamated.hpp"
#include "../include/test.hpp"

TEST_CASE("Example test", "[example]") {
    REQUIRE(1 + 1 == 2);
}

TEST_CASE("Example test foo from test.hpp", "[example_foo_test.hpp]") {
    REQUIRE(foo() == "Test");
}
