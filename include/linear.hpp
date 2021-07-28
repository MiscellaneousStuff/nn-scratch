#pragma once

#include "matrix.hpp"
#include "layer.hpp"

class Linear : public Layer {

public:
    Matrix weights;

public:
    Linear(unsigned int in_dims, unsigned int out_dims)
        : weights(in_dims, out_dims) {
            weights.random();
        }

    Matrix forward(Matrix x) override {
        return Matrix::dot(x, weights);
    }
};