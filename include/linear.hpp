#pragma once

#include "matrix.hpp"


class Linear {

public:
    Matrix *weights;

public:
    Linear(unsigned int in_dims, unsigned int out_dims);
    Matrix forward(Matrix x);
};