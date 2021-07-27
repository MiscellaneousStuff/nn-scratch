// Random
float rand_float();

// Sigmoid
float sigmoid(float x);
Matrix sigmoid(Matrix m);

// ReLU
float relu(float x);
Matrix relu(Matrix m);

// Loss Functions
float mse(float y, float y_h);
float mse(Matrix y, Matrix y_h);