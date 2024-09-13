#include <iostream>  
#include <vector>    
#include <random>    // For generating random numbers
#include <boost/chrono.hpp>  // For high resolution timing
#include "SortingAlgos.h" 

int main()
{
    // Create a vector of size 10000 to store random integers
    // std::random_device is a uniformly-distributed integer random number generator
    // std::mt19937 is a Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits.
    std::random_device rd;
    std::mt19937 eng(rd());

    // uniform_int_distribution produces random integers in a range [a, b] 
    // Here the range is set to [0, 10000]
    std::uniform_int_distribution<> distr(0, 10000);

    std::vector<int> data(10000);

    // Generate the random numbers and fill them in the vector
    for (auto& num : data)
    {
        num = distr(eng);
    }

    // Creating copies of the original vector, so each sorting algorithm works with exactly the same data
    std::vector<int> copy1(data), copy2(data), copy3(data);

    // Timing the execution of QuickSort
    // The high_resolution_clock is a typedef for the clock with the smallest tick period provided by the implementation
    
    auto start = boost::chrono::high_resolution_clock::now();
    
    SortingAlgos::quickSort(copy1, 0, copy1.size() - 1);  // Calling the QuickSort function from SortingAlgos class
    
    auto end = boost::chrono::high_resolution_clock::now();
   
    
    // duration_cast converts the duration to from nanoseconds (standardmicroseconds 
    auto duration = boost::chrono::duration_cast<boost::chrono::microseconds>(end - start);
    std::cout << "Quicksort: " << duration.count() << " microseconds\n";  // Output the elapsed time

    // Time the execution of MergeSort
    start = boost::chrono::high_resolution_clock::now();
    SortingAlgos::mergeSort(copy2, 0, copy2.size() - 1);  // Call the MergeSort function from SortingAlgos class
    end = boost::chrono::high_resolution_clock::now();
    duration = boost::chrono::duration_cast<boost::chrono::microseconds>(end - start);
    std::cout << "Mergesort: " << duration.count() << " microseconds\n";  // Output the elapsed time

    // Time the execution of HeapSort
    start = boost::chrono::high_resolution_clock::now();
    SortingAlgos::heapSort(copy3);  // Call the HeapSort function from SortingAlgos class
    end = boost::chrono::high_resolution_clock::now();
    duration = boost::chrono::duration_cast<boost::chrono::microseconds>(end - start);
    std::cout << "Heapsort: " << duration.count() << " microseconds\n";  // Output the elapsed time

    return 0;  // Exit the program
}
