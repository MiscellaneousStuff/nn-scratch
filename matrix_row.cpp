#include <iostream>
#include <vector>
#include <cmath>

#include "include/matrix.hpp"
#include "include/matrix_row.hpp"
#include "include/funcs.hpp"

MatrixRow::MatrixRow(std::vector<float> data) {
    r = data;
};

MatrixRow::MatrixRow(float value) {
    r = std::vector<float>{value};
}

MatrixRow::MatrixRow(unsigned int cols) {
    r.resize(cols);
}

MatrixRow::MatrixRow(unsigned int cols, float value) {
    r.resize(cols, value);
}

size_t MatrixRow::size() {
    return r.size();
}

float& MatrixRow::operator() (unsigned int col) {
    return r[col];
}

MatrixRow MatrixRow::operator*= (const MatrixRow &other) {
    std::vector<float> copy;

    // *= element-wise
    int n = this->size();
    for (int i=0; i<n; i++) {
        copy.push_back(r[i] *= other.r[i]);
    }

    return MatrixRow(copy);
}

MatrixRow MatrixRow::operator-= (const MatrixRow &other) {
    std::vector<float> copy;

    // -= element-wise
    int n = this->size();
    for (int i=0; i<n; i++) {
        copy.push_back(r[i] -= other.r[i]);
    }

    return MatrixRow(copy);
}

MatrixRow MatrixRow::power(float value) {
    std::vector<float> copy;

    int n = this->size();
    for (int i=0; i<n; i++) {
        float val = pow(r[i], 2);
        copy.push_back(val);
    }

    return MatrixRow(copy);
}

float MatrixRow::sum() {
    float n = 0;
    for (int i=0; i<r.size(); i++) {
        n += r[i];
    }
    return n;
}

void MatrixRow::random() {
    for (float& elem : r) {
        elem = rand_float();
    }
}

std::string MatrixRow::to_string() {
    std::string row_out("\t[");
    for (size_t c=0; c<this->size(); c++) {
        float elem = r[c];
        row_out += std::to_string(elem) + ", ";
    }
    row_out += "],\n";
    return row_out;
}