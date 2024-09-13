#include "ArrayGenerator.h"

// Constructor initializes the random number generator with a seed value
ArrayGenerator::ArrayGenerator()
    : gen(std::random_device{}())  // Initialize Mersenne Twister random number generator with a non-deterministic seed
{
}

// Generate an array of specified size, with values from a uniform distribution in the range [minVal, maxVal]
std::vector<int> ArrayGenerator::generateUniformArray(int size, int minVal, int maxVal) 
{
    std::uniform_int_distribution<int> distribution(minVal, maxVal);

    std::vector<int> array(size);
    for (int i = 0; i < size; ++i) 
    {
        array[i] = distribution(gen);
    }

    return array;
}

// Generate a sorted array of specified size, with values from 1 to size
std::vector<int> ArrayGenerator::generateSortedArray(int size)
{
    std::vector<int> array(size);
    for (int i = 0; i < size; ++i) 
    {
        array[i] = i + 1;
    }

    return array;
}

// Generate a reverse sorted array of specified size, with values from size to 1
std::vector<int> ArrayGenerator::generateReverseSortedArray(int size) 
{
    std::vector<int> array(size);
    for (int i = 0; i < size; ++i) 
    {
        array[i] = size - i;
    }

    return array;
}

std::vector<int> ArrayGenerator::generateFewUniqueArray(int size, int numUnique)
{
    std::vector<int> array(size);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, numUnique);

    for (int i = 0; i < size; i++)
    {
        array[i] = distribution(generator);
    }

    return array;
}
