# Description
Simulation of one hunter and one or multiple prey. C++ version of [hunter-killer](https://github.com/maxboro/hunter-killer).
# How to run
#### Simulation:
```bash
make           # Builds the project
./bin/game     # Runs the executable
```

#### Unit tests:
```bash
make test      # Builds the unit tests
./bin/tests    # Runs the executable of tests
```

#### Clean:
```bash
make clean     # Cleans up build files
```

### Example 
```terminal
Reading the settings.
n_prey: 5
n_steps: 20
grid_size_x: 5
grid_size_y: 5
show_grid: 1
Settings are loaded.
```
# Credits
Testing framework: [Catch2](https://github.com/catchorg/Catch2) (licensed under the Boost Software License)