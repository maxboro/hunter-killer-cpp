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
# Settings
In file `settings.txt` you can modify simulation parameters.
- `n_prey` (int: default 2) - Number of prey
- `n_steps` (int: default 20) - Number of simulation steps
- `grid_size_x` (int: default 5) - Grid size in X dimension
- `grid_size_y` (int: default 5) - Grid size in Y dimension
- `show_grid` (int: default 1) - Flag to show grid (1/0)

# Credits
Testing framework: [Catch2](https://github.com/catchorg/Catch2) (licensed under the Boost Software License)

# Example 
```terminal
Reading the settings.
n_prey: 5
n_steps: 20
grid_size_x: 5
grid_size_y: 5
show_grid: 1
Settings are loaded.
Prey_0 at Loc[0; 3]. Alive
Prey_1 at Loc[4; 3]. Alive
Prey_2 at Loc[3; 0]. Alive
Prey_3 at Loc[1; 3]. Alive
Prey_4 at Loc[1; 1]. Alive
Hunter at Loc[0; 4]. Alive
 | | |P| |
 |P| | | |
 | | | | |
P|P| | |P|
H| | | | |

Prey_0 at Loc[0; 3]. Alive
Prey_1 at Loc[4; 3]. Alive
Prey_2 at Loc[3; 0]. Alive
Prey_3 at Loc[0; 3]. Alive
Prey_4 at Loc[1; 0]. Alive
Hunter at Loc[0; 4]. Alive
 |P| |P| |
 | | | | |
 | | | | |
P| | | |P|
H| | | | |

Prey_0 at Loc[0; 3]. Alive
Prey_1 at Loc[4; 4]. Alive
Prey_2 at Loc[2; 0]. Alive
Prey_3 at Loc[0; 3]. Alive
Prey_4 at Loc[0; 0]. Alive
Hunter at Loc[0; 4]. Alive
P| |P| | |
 | | | | |
 | | | | |
P| | | | |
H| | | |P|

Prey_0 at Loc[1; 3]. Alive
Prey_1 at Loc[3; 4]. Alive
Prey_2 at Loc[2; 0]. Alive
Prey_3 at Loc[0; 2]. Alive
Prey_4 at Loc[0; 0]. Alive
Hunter at Loc[0; 3]. Alive
P| |P| | |
 | | | | |
P| | | | |
H|P| | | |
 | | |P| |

Prey_0 at Loc[2; 3]. Alive
Prey_1 at Loc[3; 4]. Alive
Prey_2 at Loc[3; 0]. Alive
Prey_3 at Loc[0; 2]. Alive
Prey_4 at Loc[0; 0]. Alive
Hunter at Loc[0; 3]. Alive
P| | |P| |
 | | | | |
P| | | | |
H| |P| | |
 | | |P| |

Prey_3 is killed.
Prey_0 at Loc[2; 3]. Alive
Prey_1 at Loc[3; 4]. Alive
Prey_2 at Loc[3; 1]. Alive
Prey_3 at Loc[0; 3]. Dead
Prey_4 at Loc[0; 0]. Alive
Hunter at Loc[0; 3]. Alive
P| | | | |
 | | |P| |
 | | | | |
H| |P| | |
 | | |P| |

Prey_0 at Loc[2; 2]. Alive
Prey_1 at Loc[3; 4]. Alive
Prey_2 at Loc[4; 1]. Alive
Prey_3 at Loc[0; 3]. Dead
Prey_4 at Loc[0; 0]. Alive
Hunter at Loc[0; 2]. Alive
P| | | | |
 | | | |P|
H| |P| | |
X| | | | |
 | | |P| |
```
