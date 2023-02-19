// Implement function
// int findMax(int* arr, int length){}
// to find the largest element using recursion (with length is the number of elements in integer array arr).
// Please note that you can't using key work for, while, goto (even in variable names, comment).
// For this exercise, we have #include <iostream> and using namespace std;
// For example:
// Test	       Result
// int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
// cout << findMax(arr, 10);  15

int findMax(int* arr, int length)
{
    /*  
     * STUDENT ANSWER
     */
    if( length == 0){
        return -1;
    }
    if( length == 1){
        return arr[0];
    }
    else {
        if (arr[length - 1] > findMax(arr, length - 1)){ 
            return arr[length-1];
        }
        else {
            return findMax(arr, length - 1);
        }
    }
    
}