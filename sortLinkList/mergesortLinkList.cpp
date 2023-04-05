Implement static methods Merge and MergeSort in class Sorting to sort an array in ascending order. The Merge method has already been defined a call to method printArray so you do not have to call this method again to print your array.


#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    static void merge(T* left, T* middle, T* right){
        /*TODO*/
        Sorting::printArray(left, right);
    }
    static void mergeSort(T* start, T* end) {
       /*TODO*/
    }
};
#endif /* SORTING_H */

For example:

Test	Result
int arr[] = {0,2,4,3,1,4};
Sorting<int>::mergeSort(&arr[0], &arr[5]);
0, 2
0, 2, 4
1, 3
1, 3, 4
0, 1, 2, 3, 4, 4
int arr[] = {1};
Sorting<int>::mergeSort(&arr[0], &arr[0]);
static void merge(T* left, T* middle, T* right){
    /*TODO*/
        int sizeLeft = middle - left + 1;
        int sizeRight = right - middle;

        // Create temporary arrays
        T* tempLeft = new T[sizeLeft];
        T* tempRight = new T[sizeRight];

        // Copy data to temporary arrays
        for (int i = 0; i < sizeLeft; i++)
            tempLeft[i] = left[i];
        for (int i = 0; i < sizeRight; i++)
            tempRight[i] = middle[1 + i];

        // Merge the temporary arrays back into left[start..end]
        int i = 0; // Initial index of first subarray
        int j = 0; // Initial index of second subarray
        int k = 0; // Initial index of merged subarray
        while (i < sizeLeft && j < sizeRight) {
            if (tempLeft[i] <= tempRight[j]) {
                left[k] = tempLeft[i];
                i++;
            }
            else {
                left[k] = tempRight[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of tempLeft, if any
        while (i < sizeLeft) {
            left[k] = tempLeft[i];
            i++;
            k++;
        }

        // Copy the remaining elements of tempRight, if any
        while (j < sizeRight) {
            left[k] = tempRight[j];
            j++;
            k++;
        }

        // Free the temporary arrays
        delete[] tempLeft;
        delete[] tempRight;

        // Print the merged array
        Sorting::printArray(left, right);
}
static void mergeSort(T* start, T* end){
        /*TODO*/
    if (start < end) {
            // Find the middle point
        T* middle = start + (end - start) / 2;

            // Sort first and second halves
        Sorting<T>::mergeSort(start, middle);
        Sorting<T>::mergeSort(middle + 1, end);

            // Merge the sorted halves
        Sorting<T>::merge(start, middle, end);
    }
}
