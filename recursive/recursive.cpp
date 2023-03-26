#include<iostream>
#include<conio.h>
#include<vector>

using namespace std;


int findMax(int* arr,int length){
    if(length == 0){
        return -1;
    }
    if(length == 1){
        return arr[0];
    }
    else {
        if(arr[length - 1] > findMax(arr,length - 1)){
            return arr[length -1];
        }
        else {
            return findMax(arr,length-1);
        }
    }
}
int sum(int n){
    if(n == 1){
        return 1;
    } else {
        return n + sum(n - 1);
    }
}
int sumArray(int* arr, int length){
    int sum = arr[length - 1];
    if(length == 1){
        return 1;
    }
    else {
        return (sumArray(arr, length - 1) + sum);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = l;

    /* create temp array */
    int temp[5];

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        } else {
            temp[k] = arr[j];
            j++;
            k++;
        }

    }

    /* Copy the remaining elements of first half, if there are any */
    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;

    }

    /* Copy the remaining elements of second half, if there are any */
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    /* Copy the temp array to original array */
    for (int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // find midpoint
        int m = (l + r) / 2;

        // recurcive mergesort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // merge
        merge(arr, l, m, r);
    }
}

int main() {
    // int arr[] = { 10, 5, 7, 9, 15, 6, 11, 8, 12, 2 };
    // cout << findMax(arr, 10);
    // cout << sumArray(arr,10);
    // cout << sum(25);
    int myarray[10] = { 10, 5, 7, 9, 15, 6, 11, 8, 12, 2 };
    int arr_size = sizeof(myarray)/sizeof(myarray[0]);
    //int arr_size = 5;

//    cout << "Enter 5 integers in any order: " << endl;
//    for (int i = 0; i < arr_size; i++) {
//        cin >> myarray[i];
//    }
    cout << "Before Sorting" << endl;
    for (int i = 0; i < arr_size; i++) {
        cout << myarray[i] << " ";
    }
    cout << endl;
    mergeSort(myarray, 0, (arr_size - 1)); // mergesort(arr,left,right) called

    cout << "After Sorting" << endl;
    for (int i = 0; i < arr_size; i++) {
        cout << myarray[i] << " ";
    }

    return 0;
}
