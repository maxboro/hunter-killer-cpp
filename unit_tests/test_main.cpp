#define CATCH_CONFIG_MAIN
#include <string>

#include "../external/catch2/catch_amalgamated.hpp"
#include "../include/test.hpp"
#include "../include/settings.hpp"


TEST_CASE("Example test", "[example]") {
    REQUIRE(1 + 1 == 2);
}

TEST_CASE("Example test foo from test.hpp", "[example_foo_test.hpp]") {
    REQUIRE(foo() == "Test");
}

TEST_CASE("Settings.hpp", "[settings.hpp]") {
    std::string settings_keys[5] = {"n_prey", "n_steps", "grid_size_x", "grid_size_y", "show_grid"};

    Settings* settings = Settings::get_instance();
    settings->load_settings();

    // present keys
    for (std::string key : settings_keys){
        REQUIRE_NOTHROW(settings->get_value(key));

        // check all setting are int
        std::string value_type = typeid(settings->get_value(key)).name();
        REQUIRE(value_type == "i"); 
    }

    // not present keys
    REQUIRE_THROWS(settings->get_value("ffrfrfr"));
}
