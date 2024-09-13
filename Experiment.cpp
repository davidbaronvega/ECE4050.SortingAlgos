#include "Experiment.h"

Experiment::Experiment(std::vector<int> arraySizes) : arraySizes(arraySizes) {}

void Experiment::run() 
{
    // For each size specified within the function-
    for (int size : arraySizes) 
    {
        // -Generate different types of arrays of this size:
        std::vector<int> randomArray = arrayGenerator.generateUniformArray(size, 0, 100);
        std::vector<int> sortedArray = arrayGenerator.generateSortedArray(size);
        std::vector<int> reversedArray = arrayGenerator.generateReverseSortedArray(size);
        std::vector<int> fewUniqueArray = arrayGenerator.generateFewUniqueArray(size, size / 10);

        // Test the sorting algorithms on these arrays and measure the execution times
        // TODO: Implement this
    }
}
