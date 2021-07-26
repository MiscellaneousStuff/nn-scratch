#include <iostream>
#include <vector>

class Matrix {
    std::vector<std::vector<float>> m;
public:
    Matrix(unsigned int rows, unsigned int cols) {
        m.resize(rows, std::vector<float>(cols, 0.f));
        size_t size = rows * cols;
        size_t i = 0;
        for (size_t r=0; r<rows; r++) {
            for (size_t c=0; c<cols; c++) {
                m[r][c] = i++;
            }
        }
    }

    std::vector<float>& operator() (unsigned int row) {
        return m[row];
    }
    float& operator() (unsigned int row, unsigned int col) {
        return m[row][col];
    }

    std::string to_string() {
        std::string out("[\n");
        for (size_t r=0; r<m.size(); r++) {
            std::string row_out("\t[");
            std::vector<float> row = m[r];
            for (size_t c=0; c<row.size(); c++) {
                float elem = row[c];
                row_out += std::to_string(elem) + ", ";
            }
            row_out += "],\n";
            out += row_out;
        }
        out += "]\n";
        return out;
    };
};

int main() {
    Matrix m(2, 1);
}