//
// Created by User on 2020-06-09.
//

#include "perceptron.h"

perceptron::perceptron(std::vector<std::vector<float>> trainingData)  : threshold(1), weights(3, 0.0F) {
    this->trainingData.resize(trainingData.size());
    for (int i = 0; i < trainingData.size(); ++i) {
        this->trainingData[i] = std::move(trainingData[i]);
    }
}

const std::vector<float> &perceptron::getWeights() const {
    return weights;
}
