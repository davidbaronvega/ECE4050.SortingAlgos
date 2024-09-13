#include "SortingAlgos.h"

using namespace std;

// The partition function takes the last element as pivot, places the pivot element at its correct position 
// in the sorted array, and places all elements smaller than the pivot to the left of the pivot, 
// and all elements greater than the pivot to the right.
int SortingAlgos::partition(vector<int>& data, int low, int high)
{
    int pivot = data[high]; // pivot  
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot  
        if (data[j] < pivot)
        {
            i++; // increment index of smaller element  
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return (i + 1);
}

// QuickSort function that sorts data[low..high] using partition(). 
void SortingAlgos::quickSort(vector<int>& data, int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, data[pi] is now at right place 
        int pi = partition(data, low, high);

        // Separately sort elements before and after partition 
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

// Merges two subarrays of data[]. 
// First subarray is data[low..mid] 
// Second subarray is data[mid+1..high] 
void SortingAlgos::merge(vector<int>& data, int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // create temp arrays 
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[] 
    for (i = 0; i < n1; i++)
        L[i] = data[low + i];
    for (j = 0; j < n2; j++)
        R[j] = data[mid + 1 + j];

    // Merge the temp arrays back into data[low..high]
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = low; // Initial index of merged subarray 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any 
    while (i < n1)
    {
        data[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any 
    while (j < n2)
    {
        data[k] = R[j];
        j++;
        k++;
    }
}

// MergeSort function that sorts data[low..high] using merge() 
void SortingAlgos::mergeSort(vector<int>& data, int low, int high)
{
    if (low < high)
    {
        // Same as (low+high)/2, but avoids overflow for large low and high 
        int mid = low + (high - low) / 2;

        // Sort first and second halves 
        mergeSort(data, low, mid);
        mergeSort(data, mid + 1, high);

        merge(data, low, mid, high);
    }
}

// To heapify a subtree rooted with node i which is an index in data[]. n is size of heap 
void SortingAlgos::heapify(vector<int>& data, int n, int i)
{
    int largest = i; // Initialize largest as root 
    int left = 2 * i + 1; // left = 2*i + 1 
    int right = 2 * i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (left < n && data[left] > data[largest])
        largest = left;

    // If right child is larger than largest so far 
    if (right < n && data[right] > data[largest])
        largest = right;

    // If largest is not root 
    if (largest != i)
    {
        swap(data[i], data[largest]);

        // Recursively heapify the affected sub-tree 
        heapify(data, n, largest);
    }
}

// Function to perform HeapSort for array data[]
void SortingAlgos::heapSort(vector<int>& data)
{
    int n = data.size();

    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(data, n, i);

    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end 
        swap(data[0], data[i]);

        // call max heapify on the reduced heap 
        heapify(data, i, 0);
    }
}
