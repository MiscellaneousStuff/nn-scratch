#include <iostream>
#include <vector>
#include <cmath>


class MatrixRow {

public:
    std::vector<float> r;

public:
    MatrixRow(std::vector<float> data) {
        r = data;
    };
    MatrixRow(unsigned int cols) {
        r.resize(cols);
    }
    MatrixRow(unsigned int cols, float value) {
        r.resize(cols, value);
    }
    size_t size() {
        return r.size();
    }
    float& operator() (unsigned int col) {
        return r[col];
    }
    MatrixRow operator*= (const MatrixRow &other) {
        std::vector<float> copy;

        // *= element-wise
        int n = this->size();
        for (int i=0; i<n; i++) {
            copy.push_back(r[i] *= other.r[i]);
        }

        return MatrixRow(copy);
    }
    float sum() {
        float n = 0;
        for (int i=0; i<r.size(); i++) {
            n += r[i];
        }
        return n;
    }
    std::string to_string() {
        std::string row_out("\t[");
        for (size_t c=0; c<this->size(); c++) {
            float elem = r[c];
            row_out += std::to_string(elem) + ", ";
        }
        row_out += "],\n";
        return row_out;
    }
};


class Matrix {

public:
    std::vector<MatrixRow> m;

public:
    Matrix(std::vector<MatrixRow> data) {
        m = data;
    };

    Matrix(MatrixRow data) {
        m.clear();
        m.push_back(data);
    };

    Matrix(unsigned int rows, unsigned int cols) {
        m.resize(rows, MatrixRow(cols, 0.f));
        size_t size = rows * cols;
        size_t i = 0;
        for (size_t r=0; r<rows; r++) {
            for (size_t c=0; c<cols; c++) {
                m[r](c) = i++;
            }
        }
    }

    std::pair<size_t, size_t> shape() {
        return std::pair<size_t, size_t>(this->rows(), this->cols());
    }

    Matrix& operator=(const Matrix &other) {
        if (this != &other) {
            m = other.m;
        }
        return *this;
    }

    void transpose() {
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

    size_t size() {
        size_t rows = m.size();
        size_t cols = m[0].size();
        return rows * cols;
    }

    size_t rows() {
        return m.size();
    }

    size_t cols() {
        return m[0].size();
    }

    MatrixRow& operator() (int idx) {
        if (idx > -1) {
            // Row: idx > -1
            return m[idx];
        } else {
            // Col: idx

        }
    }
    float& operator() (unsigned int row, unsigned int col) {
        return m[row](col);
    }
    
    std::string shape_to_string() {
        std::pair<size_t, size_t> shape = this->shape();
        return std::string("(" + std::to_string(shape.first) + ", " + std::to_string(shape.second) + ")");
    }

    std::string to_string() {
        std::string out("[\n");
        for (size_t r=0; r<m.size(); r++) {
            out += m[r].to_string();;
        }
        out += "]\n";
        return out;
    };

    static float dot(Matrix a, Matrix b) {
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
};


float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}


Matrix sigmoid(Matrix m) {
    return m;
};


/*
class Layer {
    // Dummy Class (Not sure how to do this properly in C++ tbh :/)
public:
    virtual Matrix forward(void *input);
};
*/

//class Linear : public Layer {
class Linear {

public:
    Matrix weights;

public:
    Linear(unsigned int in_dims, unsigned int out_dims)
        : weights(in_dims, out_dims) {};
    Matrix forward(Matrix x) {
        return Matrix(1, 1);
    }
};


class NeuralNetwork {

public:
    std::vector<Linear> layers;
    unsigned int _in_dims;
    unsigned int _out_dims;

public:
    NeuralNetwork(unsigned int in_dims, unsigned int out_dims) {
        in_dims = _in_dims;
        out_dims = _out_dims;

        Linear fc1 = Linear(in_dims, out_dims);
        layers.push_back(fc1);
    }
    Matrix forward(Matrix x) {
        x = layers.at(0).forward(x);
        x = sigmoid(x);
        return x;
    }
};


int main() {
    Matrix input(std::vector<float>{1, 0.9});
    Matrix weights(std::vector<float>{0.4, 0.3});

    float Z = Matrix::dot(input, weights);

    std::cout << "Inputs:\n" << input.to_string() << "\n";
    std::cout << "Weights:\n" << weights.to_string() << "\n";
    std::cout << "Z:\n" << std::to_string(Z) << "\n";
    std::cout << "Activation:\n" << sigmoid(Z) << "\n";
    
    return 0;
}