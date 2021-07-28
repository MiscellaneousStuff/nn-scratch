#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include <cmath>
#include <ctime>
#include <cstdlib>

#include "include/matrix.hpp"
#include "include/linear.hpp"
#include "include/funcs.hpp"

 
class NeuralNetwork {

public:
    std::vector<std::shared_ptr<Layer>> layers;
    unsigned int _in_dims;
    unsigned int _out_dims;

public:
    NeuralNetwork(unsigned int in_dims, unsigned int out_dims) {
        // Init dims
        _in_dims = in_dims;
        _out_dims = out_dims;

        // Init layers
        auto fc1 = std::make_shared<Linear>(in_dims, out_dims);

        // Append layers
        layers.push_back(fc1);
    }
    Matrix forward(Matrix x) {
        x = layers.at(0)->forward(x);
        x = sigmoid(x);
        return x;
    }
    void train(std::vector<Matrix> inputs, std::vector<Matrix> outputs,
        float learning_rate=0.01, int epochs=1) {
            std::vector<float> losses;
            for (int e=0; e<epochs; e++) {
                for (int i=0; i<inputs.size(); i++) {
                    Matrix input  = inputs[i];
                    Matrix output = outputs[i];
                    Matrix pred = this->forward(input);
                    float loss = mse(output, pred);
                    losses.push_back(loss);
                }
                float mean_loss = MatrixRow(losses).sum();
                std::cout << "Mean Loss: " << mean_loss << "\n";
            }
    }
};


int main() {
    srand(static_cast<unsigned> (time(0)));

    // OR Inputs
    std::vector<Matrix> inputs = {
        Matrix(std::vector<float>{0.0, 0.0}),
        Matrix(std::vector<float>{0.0, 1.0}),
        Matrix(std::vector<float>{1.0, 0.0}),
        Matrix(std::vector<float>{1.0, 1.0})
    };

    // OR Outputs
    std::vector<Matrix> outputs = {
        Matrix(std::vector<float>{0.0}),
        Matrix(std::vector<float>{1.0}),
        Matrix(std::vector<float>{1.0}),
        Matrix(std::vector<float>{1.0})
    };

    NeuralNetwork nn(2, 1);
    nn.train(inputs, outputs);

    return 0;
}