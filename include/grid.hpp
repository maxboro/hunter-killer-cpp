#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <vector>
#include <string>

class Grid {
public:
    Grid(int size_x, int size_y): 
        _size_x(size_x), 
        _size_y(size_y),
        _grid(size_x, std::vector<char>(size_y, ' ')){};

    void set_empty_grid(){
        _grid = std::vector(_size_x, std::vector<char>(_size_y, ' '));
    }

    void set_cell_value(int coord_x, int coord_y, char sign){
        _grid[coord_y][coord_x] = sign;
    }

    char get_cell_value(int coord_x, int coord_y) const {
        return _grid[coord_y][coord_x];
    }

    std::string get_grid() const {
        std::string grid_str = "";
        for (auto& line : _grid){
            for (const char& el : line){
                std::string el_cell = std::string(1, el) + "|";
                grid_str = grid_str + el_cell;
            }
            grid_str += "\n";
        }
        return grid_str;
    }

    void show_grid() const {
        std::string grid_str = get_grid();
        std::cout << grid_str << std::endl;
    }
    
private:
    int _size_x;
    int _size_y;
    std::vector<std::vector<char>> _grid;
};

#endif
