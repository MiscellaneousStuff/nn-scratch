#pragma once

#include <iostream>
#include <vector>
#include <cmath>

#include "matrix_row.hpp"


class Matrix {
public:
    std::vector<MatrixRow> m;
public:
    // Constructors
    Matrix(std::vector<MatrixRow> data);
    Matrix(float value);
    Matrix(MatrixRow data);
    Matrix(unsigned int rows, unsigned int cols);

    // Transformers
    void transpose();
    
    // Setters
    Matrix& operator=(const Matrix &other);
    void random();

    // Getters
    size_t size();
    size_t rows();
    size_t cols();
    MatrixRow& operator() (int idx);
    float& operator() (unsigned int row, unsigned int col);
    std::pair<size_t, size_t> shape();

    // String
    std::string shape_to_string();
    std::string to_string();

    // Static Transformers
    static float dot(Matrix a, Matrix b);
};