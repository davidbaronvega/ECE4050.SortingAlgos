#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <chrono>
#include <vector>
#include "SortingAlgos.h"
#include "ArrayGenerator.h"

class Experiment 
{
private:
    SortingAlgos sortingAlgos;
    ArrayGenerator arrayGenerator;
    std::vector<int> arraySizes; // The different sizes of arrays to test

public:
    Experiment(std::vector<int> arraySizes);
    void run(); // Run the experiment
};

#endif //EXPERIMENT_H
