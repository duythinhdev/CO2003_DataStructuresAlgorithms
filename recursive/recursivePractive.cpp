#include<iostream>
#include<conio.h>

using namespace std;


int findMax(int* arr,int length){
    if(length == 0){
        return -1;
    }if(length == 1){
        return arr[0];
    }else {
        if(arr[length - 1] > findMax(arr,length - 1)){
            return arr[length -1];
        }
        else {
            return findMax(arr,length-1);
        }
    }
}
int findMax1(int* arr,int length) {
    if(length == 0 ){
        return -1;
    }if(length == 1){
        return arr[0];
    }else {
        if(arr[length -1] > findMax1(arr,length - 1)){
            return arr[length - 1];
        } else {
            return findMax1(arr,length-1);
        }
    }
}
void printArray(int n){
    if(n == 0){
        cout << "0";
    }else {
        printArray(n - 1);
        cout << ", " << n;
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

void quickSort(int a[], int l, int r){
    int p = a[(l+r)/2];
    int i = l, j = r;
    while (i < j){
        while (a[i] < p){
            i++;
        }
        while (a[j] > p){
            j--;
        }
        if (i <= j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r){
        quickSort(a, i, r);
    }
    if (l < j){
        quickSort(a, l, j);
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int findLCM(int a, int b) {
    int lcm = (a * b) / gcd(a, b);
    return lcm;
}
int strLen(char* str) {
    if (*str == '\0') {
        return 0;
    } else {
        return 1 + strLen(str + 1);
    }
}
int strLen1(char* str){
    if(*str == '\0'){
        return 0;
    }else {
        return 1 + strLen(str + 1);
    }
}
string reverseSentence(string s) {
    size_t space_index = s.find(' ');
    if (space_index == string::npos) {
        return s;
    }
    else {
        string first_word = s.substr(0, space_index);
        string rest_of_sentence = s.substr(space_index + 1);
        return reverseSentence(rest_of_sentence) + ' ' + first_word;
    }
}
int main() {
    //     int arr[] = { 10, 5, 7, 9, 15, 6, 11, 8, 12, 2 };
    //     cout << findMax1(arr, 10);
    //     cout <<  findLCM(10, 102);
    //    char str[] = "Truong DH Bach Khoa";
    //    cout << strLen(str);
    cout << reverseSentence("data structure and algorithm is scary");
    // cout << sumArray(arr,10);
    // cout << sum(25);
    //    int myarray[10] = { 10, 5, 7, 9, 15, 6, 11, 8, 12, 2 };
    //    int arr_size = sizeof(myarray)/sizeof(myarray[0]);
        //int arr_size = 5;

    //    cout << "Enter 5 integers in any order: " << endl;
    //    for (int i = 0; i < arr_size; i++) {
    //        cin >> myarray[i];
    //    }
    //    cout << "Before Sorting" << endl;
    //    for (int i = 0; i < arr_size; i++) {
    //        cout << myarray[i] << " ";
    //    }
    //    cout << endl;
    //    mergeSort(myarray, 0, (arr_size - 1)); // mergesort(arr,left,right) called
    //
    //    cout << "After Sorting" << endl;
    //    for (int i = 0; i < arr_size; i++) {
    //        cout << myarray[i] << " ";
    //    }
    //    int arr[9] = {5, 12, 7, 1, 13, 2 ,23, 11, 18};
    //
    //    cout << "Unsorted array : ";
    //    for (int i = 0; i < 9; i++)
    //    {
    //        cout << arr[i] << " ";
    //    }
    //    printf("\n");
    //
    //    quickSort1(arr, 0, 9 - 1);
    //
    //    cout << "Sorted array : ";
    //    for (int i = 0; i < 9; i++)
    //    {
    //        cout << arr[i] << " ";
    //    }
    //    printArray(5);
    return 0;
}
