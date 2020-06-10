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
    const std::vector<float> &getWeights() const;

public:
    perceptron(std::vector<std::vector<float>> trainingData);
    void trainPerceptron(int iterations, float learningRate);
    int compute(float in1, float in2);



};

#endif //ASSIGNMENT_7_PERCEPTRON_H
