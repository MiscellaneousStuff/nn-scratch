#pragma once

#include "matrix.hpp"

class Layer {
public:
    virtual Matrix forward(Matrix x) {}
};