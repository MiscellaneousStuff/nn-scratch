#pragma once

#include <iostream>
#include <vector>
#include <cmath>

#include "include/matrix.hpp"

float rand_float() {
    //float rand_float = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return (float) (rand() / RAND_MAX);
}

float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}

Matrix sigmoid(Matrix m) {
    return m;
};

float relu(float x) {
    return std::max(0.f, x);
}

Matrix relu(Matrix m) {
    return m;
}