#pragma once

#include "matrix.hpp"


class Linear {

public:
    Matrix weights;

public:
    Linear(unsigned int in_dims, unsigned int out_dims)
        : weights(in_dims, out_dims) {
            weights.random();
        }
    Matrix forward(Matrix x);
};