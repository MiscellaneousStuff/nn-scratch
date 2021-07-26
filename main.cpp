#include <iostream>
#include <vector>
#include <cmath>


class MatrixRow {

private:
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
};


class Matrix {

private:
    std::vector<MatrixRow> m;

public:
    Matrix(std::vector<MatrixRow> data) {
        m = data;
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

    static void copy(Matrix source, Matrix destination) {
        size_t source_rows = source.rows();
        size_t source_cols = source.cols();
        for (size_t c=0; c<source_cols; c++) {
            std::vector<float> row;

        }
    }

    void transpose() {
        /*
        1. create buffer (from data) to store transposed matrix
        2. fill buffer
        3. copy buffer (to data)
        */
        size_t rows = this->rows();
        size_t cols = this->cols();

        // New buffer
        std::vector<MatrixRow> buffer_data;
        for (size_t c=0; c<cols; c++) {
            std::vector<float> row;
            for(size_t r=0; r<rows; r++) {
                row.push_back(m[r](c));
            }
            buffer_data.push_back(MatrixRow(row));
        }
        Matrix buffer(buffer_data);
        std::cout << "pre-t-buf:\n" << this->to_string() << "\n";
        std::cout << "pos-t-buf:\n" << buffer.to_string() << "\n";
        /*
        for (size_t r=0; r<rows; r++) {
            for (size_t c=0; c<cols; c++) {
                if (r != c) { // skip flip line
                    float tmp = m[r](c);
                    m[r](c) = m[c](r);
                    m[c](r) = tmp;
                }
            }
        }
        */
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

    MatrixRow& operator() (unsigned int row) {
        return m[row];
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
            std::string row_out("\t[");
            MatrixRow row = m[r];
            for (size_t c=0; c<row.size(); c++) {
                float elem = row(c);
                row_out += std::to_string(elem) + ", ";
            }
            row_out += "],\n";
            out += row_out;
        }
        out += "]\n";
        return out;
    };

    static Matrix dot(Matrix a, Matrix b) {
        /*
        // New matrix
        size_t rows = a.rows();
        size_t cols = b.cols();
        Matrix m(rows, cols);

        // Fill new matrix with values
        for (int r=0; r<rows; r++) {
            m[r] = rows[r] * cols[r];
            std::vector<float> 
            std::transform( v1.begin()+1, v1.end(),
                v2.begin()+1, v.begin(),  // assumes v1,v2 of same size > 1, 
                                          //       v one element smaller
                std::multiplies<int>() );
        }
        */
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

private:
    Matrix weights;

public:
    Linear(unsigned int in_dims, unsigned int out_dims)
        : weights(in_dims, out_dims) {};
    Matrix forward(Matrix x) {
        return Matrix(1, 1);
    }
};


class NeuralNetwork {

private:
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
    // Init data into matrix
    MatrixRow row(std::vector<float>{1, 1});
    std::vector<MatrixRow> rows{row};
    Matrix input(rows);
    // std::cout << "Input size: " << input.shape_to_string() << "\n";
    input.transpose(); // input needs to be transposed to work with neural network
    // std::cout << "Input size: " << input.shape_to_string() << "\n";

    /*
    // Initialize neural network
    NeuralNetwork nn(2, 1);

    // Forward pass test
    Matrix pred = nn.forward(input);
    std::cout << "Pred size: " << pred.size() << "\n";

    /*
    std::cout << pred.to_string() << "\n";
    */
}