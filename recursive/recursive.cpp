#include<iostream>
#include<conio.h>

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
int main() {
     int arr[] = { 10, 5, 7, 9, 15, 6, 11, 8, 12, 2 };
     cout << findMax(arr, 10);
     return 0;
}