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
        x = layers.at(0).forward(x);
        x = sigmoid(x);
        return x;
    }
};


int main() {
    srand(static_cast<unsigned> (time(0)));

    Matrix input(std::vector<float>{0.5, 0.5});
    NeuralNetwork nn(2, 1);
   
    
    Matrix pred = nn.forward(input);
    std::cout << pred.to_string();

    return 0;
}