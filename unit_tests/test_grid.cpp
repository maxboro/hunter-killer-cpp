#include "../external/catch2/catch_amalgamated.hpp"
#include "../include/grid.hpp"

TEST_CASE("Grid creation and show", "[Grid]"){
    const int n_cols = 4;
    const int n_rows = 4;

    Grid grid = Grid(n_cols, n_rows);
    REQUIRE_NOTHROW(grid.show_grid());
}

TEST_CASE("Grid setting values", "[Grid]"){
    const int n_cols = 4;
    const int n_rows = 4;

    Grid grid = Grid(n_cols, n_rows);
    REQUIRE_NOTHROW(grid.set_cell_value(1, 1, 'X'));
    REQUIRE(grid.get_cell_value(1, 1) == 'X');
}

TEST_CASE("Grid creation and set empty", "[Grid]"){
    const int n_cols = 4;
    const int n_rows = 4;

    Grid grid = Grid(n_cols, n_rows);
    REQUIRE_NOTHROW(grid.set_empty_grid());
}
