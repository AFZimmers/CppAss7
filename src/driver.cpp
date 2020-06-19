//
// Created by User on 2020-06-09.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "perceptron.h"

perceptron doTraining(const std::string& name, int iterations, float learningRate);
std::vector<std::vector<float>> getTrainingData(const std::string& fileName);
int XORComputation(float x1,float x2, perceptron AND,perceptron OR ,perceptron NAND);

int main(){

    perceptron AND = doTraining("AND", 1000, 0.1);
    perceptron NAND = doTraining("NAND", 1000, 0.1);
    perceptron OR = doTraining("OR", 1000, 0.1);

    float x1, x2;
    while (true){
        std::cout<<"Enter x1 and x2:"<<std::endl;
        std::cin >> x1;
        std::cin >> x2;
        std::cout << XORComputation(x1,x2, AND,OR ,NAND) << std::endl;
        char answer;
        std::cout << "Test again?(y/n) ";
        std::cin >> answer;
        if (answer == 'n' || answer == 'N') {
            break;
        }
    }
    return 0;
}
// training function for the preceptron
perceptron doTraining(const std::string& name, int iterations, float learningRate) {
    std::string header = "trainingData/"+name + ".txt";

    perceptron perceptron(getTrainingData(header));

    std::cout << std::endl << name << std::endl;

    perceptron.trainPerceptron(iterations, learningRate);

    std::cout << "W1: " << perceptron.getWeights()[0] << std::endl;
    std::cout << "W2: " << perceptron.getWeights()[1] << std::endl;
    std::cout << "W3: " << perceptron.getWeights()[2] << std::endl;

    return perceptron;
}
// reads in the training data
std::vector<std::vector<float>> getTrainingData(const std::string& fileName) {
    std::ifstream infile(fileName);
    std::vector<std::vector<float>> trainingData;
    if (infile.is_open()) {
        std::string line;
        while (getline(infile, line)) {
            std::stringstream inputLine(line);
            std::vector<float> data;
            for (int i = 0; i < 3; ++i) {
                float input;
                inputLine >> input;
                data.push_back(input);
            }
            trainingData.push_back(data);
        }
    } else {
        std::cout << "Couldn't open file: " << fileName << std::endl;
    }
    infile.close();

    return trainingData;
}

int XORComputation(float x1, float x2, perceptron AND, perceptron OR, perceptron NAND) {
    int outputNAND = NAND.activationFunctionStep(x1,x2);
    int outputOR = OR.activationFunctionStep(x1,x2);

    int outputAND = AND.activationFunctionStep(outputNAND,outputOR);

    return outputAND;
}
