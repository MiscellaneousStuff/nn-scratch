#pragma once

#include <iostream>
#include <vector>
#include <cmath>

#include "matrix.hpp"


class MatrixRow {
public:
    std::vector<float> r;
public:
    // Constructors
    MatrixRow(std::vector<float> data);
    MatrixRow(float value);
    MatrixRow(unsigned int cols);
    MatrixRow(unsigned int cols, float value);

    // Getters
    size_t size();
    float& operator() (unsigned int col);

    // Transformers
    MatrixRow operator*= (const MatrixRow &other);
    float sum();
    void random();
    
    // Strings
    std::string to_string();
};