//
// Created by User on 2020-06-09.
//

#ifndef ASSIGNMENT_7_PERCEPTRON_H
#define ASSIGNMENT_7_PERCEPTRON_H

#include <vector>

class perceptron{
    private:
        std::vector<std::vector<float>> trainingData;
        double threshold;
        std::vector<float> weights;

public:
    perceptron(std::vector<std::vector<float>> trainingData);
    void trainPerceptron(int iterations, float learningRate);
    int activationFunctionStep(float x1, float x2);
    const std::vector<float> &getWeights() const;


};

#endif //ASSIGNMENT_7_PERCEPTRON_H
