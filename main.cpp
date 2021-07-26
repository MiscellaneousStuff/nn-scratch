#include <iostream>
#include <vector>

class Matrix {
    std::vector<float> m;
public:
    Matrix(unsigned int rows) {
        m.resize(rows); // 1d for now
    }
    float& operator[](int index) {
        return m[index];
    }
};

int main() {
    Matrix m(10);
    m[2] = 3.f;
    std::cout << m[2];
}