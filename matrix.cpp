#include <iostream>
#include <vector>
#include <cmath>

#include "include/matrix.hpp"
#include "include/funcs.hpp"


Matrix::Matrix(std::vector<MatrixRow> data) {
    m = data;
};

Matrix::Matrix(float value) : Matrix(MatrixRow(value)) {};

Matrix::Matrix(MatrixRow data) {
    m.clear();
    m.push_back(data);
};

Matrix::Matrix(unsigned int rows, unsigned int cols) {
    m.resize(rows, MatrixRow(cols, 0.f));
}

std::pair<size_t, size_t> Matrix::shape() {
    return std::pair<size_t, size_t>(this->rows(), this->cols());
}

Matrix& Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        m = other.m;
    }
    return *this;
}

void Matrix::transpose() {
    // New buffer
    std::vector<MatrixRow> buffer_data;
    for (size_t c=0; c<this->cols(); c++) {
        std::vector<float> row;
        for(size_t r=0; r<this->rows(); r++) {
            row.push_back(m[r](c));
        }
        buffer_data.push_back(MatrixRow(row));
    }
    
    // Copy buffer (to data)
    *this = Matrix(buffer_data);
}

float Matrix::sum() {
    size_t rows_n = Matrix::rows();

    // Fill new matrix with values
    std::cout << "sum start" << "\n";
    
    float sum = 0.f;
    for (int r=0; r<rows_n; r++) {
        sum += (*this)(r).sum();
    }
    std::cout << "sum done" << "\n";
    return sum;
}

size_t Matrix::size() {
    size_t rows = m.size();
    size_t cols = m[0].size();
    return rows * cols;
}

size_t Matrix::rows() {
    return m.size();
}

size_t Matrix::cols() {
    return m[0].size();
}

MatrixRow& Matrix::operator() (int idx) {
    return m[idx];
}

float& Matrix::operator() (unsigned int row, unsigned int col) {
    return m[row](col);
}

void Matrix::random() {
    const size_t n = this->rows();
    for (MatrixRow &row : m) {
        row.random();
    };
}

std::string Matrix::shape_to_string() {
    std::pair<size_t, size_t> shape;
    shape = Matrix::shape();
    return std::string("(" + std::to_string(shape.first) + "," + std::to_string(shape.second) + ")");
}

std::string Matrix::to_string() {
    std::string out("[\n");
    for (size_t r=0; r<m.size(); r++) {
        out += m[r].to_string();
    }
    out += "]\n";
    return out;
};

float Matrix::dot(Matrix a, Matrix b) {
    // Matrix copies
    Matrix aCopy = a;
    Matrix bCopy = b;

    size_t rows = a.rows();

    // Transpose either a or b
    if (aCopy.shape() != bCopy.shape()) {
        aCopy.transpose();
    }

    // Fill new matrix with values
    // row(A) * col(B)
    std::vector<float> row_sums;
    for (int r=0; r<rows; r++) {
        MatrixRow row = aCopy(r);
        row *= bCopy(r);
        row_sums.push_back(row.sum());
    }
    return MatrixRow(row_sums).sum();
}

Matrix Matrix::subtract(Matrix a, Matrix b) {
    // Matrix copies
    Matrix aCopy = a;
    Matrix bCopy = b;

    size_t rows_n = a.rows();

    // Transpose either a or b
    if (aCopy.shape() != bCopy.shape()) {
        aCopy.transpose();
    }

    // Fill new matrix with values
    std::vector<MatrixRow> rows;
    for (int r=0; r<rows_n; r++) {
        MatrixRow row = aCopy(r);
        row -= bCopy(r);
        rows.push_back(row);
    }
    return Matrix(rows);
}

Matrix Matrix::power(Matrix a, float value) {
    Matrix aCopy = a;

    size_t rows_n = a.rows();

    // Fill new matrix with values
    std::vector<MatrixRow> rows;
    for (int r=0; r<rows_n; r++) {
        MatrixRow row = aCopy(r);
        row = row.power(value);
        rows.push_back(row);
    }
    return Matrix(rows);
}