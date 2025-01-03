#ifndef UTILS_RANDOM_HPP
#define UTILS_RANDOM_HPP

#include <random>

// Generate uniformly distributed random integer 
int random_uniform_int(int min, int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

#endif
