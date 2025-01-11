#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>

class Grid {
public:
    Grid(int size_x, int size_y): 
        _size_x(size_x), 
        _size_y(size_y),
        _grid(size_x, std::vector<char>(size_y, ' ')){};

    void set_empty_grid(){
        _grid = std::vector<std::vector<char>>(_size_x, std::vector<char>(_size_y, ' '));
    }

    void set_cell_value(int coord_x, int coord_y, char sign){
        _check_coords(coord_x, coord_y);
        _grid[coord_y][coord_x] = sign;
    }

    char get_cell_value(int coord_x, int coord_y) const {
        _check_coords(coord_x, coord_y);
        return _grid[coord_y][coord_x];
    }

    std::string to_string() const {
        std::ostringstream grid_str;
        for (const auto& line : _grid){
            grid_str << "|";
            for (const char& el : line){
                grid_str << el <<  "|";
            }
            grid_str << "\n";
        }
        return grid_str.str();
    }

    void show_grid() const {
        std::string grid_str = to_string();
        std::cout << grid_str << std::endl;
    }
    
private:
    const int _size_x;
    const int _size_y;
    std::vector<std::vector<char>> _grid;

    void _check_coords(int coord_x, int coord_y) const {
        if (coord_x < 0 || coord_x >= _size_x || coord_y < 0 || coord_y >= _size_y) {
            throw std::out_of_range("Coordinates out of bounds.");
        }
    }
};

#endif
