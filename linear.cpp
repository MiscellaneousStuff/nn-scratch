#include <iostream>
#include <vector>
#include <cmath>

#include "include/linear.hpp"

Linear::Linear(unsigned int in_dims, unsigned int out_dims) {
    *weights = Matrix(in_dims, out_dims);
};

Matrix Linear::forward(Matrix x) {
    return Matrix::dot(x, *weights);
}