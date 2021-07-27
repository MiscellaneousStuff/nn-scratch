#include <iostream>
#include <vector>
#include <cmath>

#include "include/linear.hpp"

Matrix Linear::forward(Matrix x) {
    return Matrix::dot(x, weights);
}