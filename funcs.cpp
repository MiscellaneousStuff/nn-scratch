#pragma once

#include <iostream>
#include <vector>
#include <cmath>

#include "include/matrix.hpp"

/*
================================================================================
Random
================================================================================
*/

float rand_float() {
    //float rand_float = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return static_cast<float> (rand()) / static_cast<float> (RAND_MAX);
}

/*
================================================================================
Sigmoid
================================================================================
*/

float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}

Matrix sigmoid(Matrix m) {
    return m;
};

/*
================================================================================
ReLU
================================================================================
*/

float relu(float x) {
    return std::max(0.f, x);
}

Matrix relu(Matrix m) {
    return m;
}

/*
================================================================================
Loss Functions
================================================================================
*/

float mse(float y, float y_h) {
    return pow(y - y_h, 2) / 1.f;
}

float mse(Matrix y, Matrix y_h) {
    std::cout << "Y, Y_hat:" << y.to_string() << " " << y_h.to_string() << "\n";
    
    Matrix diffs = Matrix::subtract(y, y_h);
    std::cout << "Y, Y_hat diffs:" << diffs.to_string() << "\n";

    Matrix pows = Matrix::power(diffs, 2);
    std::cout << "Y, Y_hat pows:" << pows.to_string() << "\n";
    
    float mean = pows.sum() / pows.size();
    std::cout << "Y, Y_hat mean:" << mean << "\n";

    return mean;
}