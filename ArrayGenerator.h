#ifndef ARRAYGENERATOR_H
#define ARRAYGENERATOR_H

#include <vector>
#include <random>

class ArrayGenerator 
{
public:

    // Constructor
    ArrayGenerator();

    // Generate an array of specified size, with values from a uniform distribution in the range [minVal, maxVal]
    std::vector<int> generateUniformArray(int size, int minVal, int maxVal);

    // Generate a sorted array of specified size, with values from 1 to size
    std::vector<int> generateSortedArray(int size);

    // Generate a reverse sorted array of specified size, with values from size to 1
    std::vector<int> generateReverseSortedArray(int size);
    // Generate an array with mostly same values and only a few unique values.
    std::vector<int> generateFewUniqueArray(int size, int numUnique);

private:
    std::mt19937 gen;  // Mersenne Twister random number generator, this has a non-deterministic seed value which produces random values each time the program is ran.
};

#endif //ARRAYGENERATOR_H
