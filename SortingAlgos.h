#ifndef SORTING_ALGOS_H
#define SORTING_ALGOS_H

#include <vector>

class SortingAlgos
{
public:
    // Function to perform QuickSort on vector data
    // The function takes two arguments, the starting index 'low' and the ending index 'high' of the vector to be sorted
    // This function uses divide and conquer approach to sort an array
    // It selects a 'pivot' element from the array and partitions the other elements into two sub-arrays
    // according to whether they are less than or greater than the pivot
    static void quickSort(std::vector<int>& data, int low, int high);

    // Function to partition the array on the basis of pivot
    // This function takes last element as pivot, places the pivot element at its correct position in sorted array,
    // and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
    static int partition(std::vector<int>& data, int low, int high);

    // Function to perform MergeSort on vector data
    // The function takes two arguments, the starting index 'low' and the ending index 'high' of the vector to be sorted
    // This function uses divide and conquer approach. It continuously splits an array into two halves, 
    // sorts them separately and then merges them
    static void mergeSort(std::vector<int>& data, int low, int high);

    // Function to merge two sub-arrays of data
    // It assumes that data[low..mid] and data[mid+1..high] are already sorted,
    // and merges them to form a single sorted sub-array
    static void merge(std::vector<int>& data, int low, int mid, int high);

    // Function to perform HeapSort on vector data
    // This function builds a Max-Heap and then continuously swaps the root of the heap with the last element 
    // decreasing the size of the heap by one and heapify the root element
    static void heapSort(std::vector<int>& data);

    // Function to heapify a subtree rooted with node i which is an index in data
    // This function assumes that the subtrees are already heapified
    static void heapify(std::vector<int>& data, int n, int i);
};

#endif // SORTING_ALGOS_H
