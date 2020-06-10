//
// Created by User on 2020-06-09.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//#include <experimental/filesystem>

//namespace  fs = std::experimental::filesystem;

#include "perceptron.h"

perceptron doTraining(std::string name, int iterations, float learningRate);

std::vector<std::vector<float>> getTrainingData(std::string fileName) {
    std::ifstream infile(fileName);
   // std::cout << fs::current_path().string() << std::endl;
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

int main(){

    perceptron AND = doTraining("AND", 1000, 0.1);
    perceptron NAND = doTraining("NAND", 1000, 0.1);
    perceptron OR = doTraining("OR", 1000, 0.1);
    return 0;
}

perceptron doTraining(std::string name, int iterations, float learningRate) {
    std::string header = "trainingData/"+name + ".txt";
    perceptron perceptron(getTrainingData(header));
    std::cout << std::endl << name << std::endl;
//    perceptron.trainPerceptron(iterations, learningRate);
    std::cout << "W1: " << perceptron.getWeights()[0] << std::endl;
    std::cout << "W2: " << perceptron.getWeights()[1] << std::endl;
    std::cout << "W3: " << perceptron.getWeights()[2] << std::endl;

    return perceptron;
}