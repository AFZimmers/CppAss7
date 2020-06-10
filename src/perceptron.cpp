//
// Created by User on 2020-06-09.
//

#include <iostream>
#include "perceptron.h"

perceptron::perceptron(std::vector<std::vector<float>> trainingData)  : threshold(1), weights(3, 0.0F) {
    this->trainingData.resize(trainingData.size());
    for (int i = 0; i < trainingData.size(); ++i) {
        this->trainingData[i] = std::move(trainingData[i]);
    }
}

void perceptron::trainPerceptron(int iterations, float learningRate) {
    for (int i = 0; i < iterations; ++i) {
        int errors=0;
        for(auto data: trainingData){
            float x1 = data.at(0);
            float x2 = data.at(1);
            int target = data.at(2);
            int output = 0;

            float valuesSum = activationFunctionStep(x1,x2);

            if(valuesSum==1){
                output=1;
            }
            if(output != target){
                errors+= 1;
                //reweighing the weights
                weights.at(0)+= learningRate*(target-output)*x1;
                weights.at(1)+= learningRate*(target-output)*x2;
                weights.at(2)+= learningRate*(target-output)*1;
            }

        }
        if(errors==0){
            std::cout<< "iterations: " << i+1<< std::endl;
            break;
        }
    }

}

int perceptron::activationFunctionStep(float x1, float x2) {
    float  valueSum = x1*weights[0]+ x2*weights[1]+weights[2];
    return (valueSum> threshold)?1:0 ;
}

const std::vector<float> &perceptron::getWeights() const {
    return weights;
}




