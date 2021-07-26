#include <iostream>
#include <vector>

#include <cmath>
#include <ctime>
#include <cstdlib>

#include "include/matrix.hpp"
#include "include/linear.hpp"
#include "include/funcs.hpp"


class NeuralNetwork {

public:
    std::vector<Linear> layers;
    unsigned int _in_dims;
    unsigned int _out_dims;

public:
    NeuralNetwork(unsigned int in_dims, unsigned int out_dims) {
        _in_dims = in_dims;
        _out_dims = out_dims;

        Linear fc1 = Linear(in_dims, out_dims);
        layers.push_back(fc1);
    }
    Matrix forward(Matrix x) {
        std::cout << "inputs :=" << x.to_string();
        x = layers.at(0).forward(x);
        std::cout << "weights * inputs :=" << x.to_string();
        x = sigmoid(x);
        std::cout << "sigmoid(weights * inputs) :=" << x.to_string();
        return x;
    }
};


int main() {
    srand (static_cast <unsigned> (time(0)));

    Matrix input(std::vector<float>{1, 0.9});
    NeuralNetwork nn(2, 1);

    Matrix pred = nn.forward(input);

    std::cout << pred.to_string();

    return 0;
}