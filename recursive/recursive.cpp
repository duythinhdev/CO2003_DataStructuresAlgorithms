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
void merge(int a[],int l, int m, int r){
    vector<int> x(a+l,a+m+1);
    vector<int> y(a+m+1, a+r+1);
    int i = 0;
    int j = 0;
    while( i < x.size() && j < y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i];
            ++l;
            ++i;
        }
        else {
            a[l] = y[j];
            ++l;
            ++i;
        }
    }
    while(i < x.size()){
        a[l] = x[i];
        ++l;
        ++i;
    }
    while(j < y.size()){
        a[l] = y[j];
        ++l;
        ++j;
    }
}
void mergeSort(int a[],int l,int r){
    if(l >= r)return; // Nếu mảng còn ít nhất 1 phần
    int m = (l + r) / 2;  //  biến để lưu vị trí chia đôi mảng
    mergeSort(a,l,m); // Đệ quy mảng trái
    mergeSort(a,m + 1,r); // Đệ quy mảng phải
    merge(a, l ,m , r);  // Trộn hai mảng lại
}
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main() {
     // int arr[] = { 10, 5, 7, 9, 15, 6, 11, 8, 12, 2 };
     // cout << findMax(arr, 10);
     // cout << sumArray(arr,10);
     // cout << sum(25);
    int arr[] = { 12, 11, 13, 5, 6, 7 , 9 , 10};
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}