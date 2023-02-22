#include<iostream>
#include<conio.h>
#include<string>
#include<regex>
#include<string.h>
using namespace std;

void printPattern(int n) {
    bool isPlus = false;
    int lon = n;
    for (int i = 0 ; i < lon; i ++) {
        if (!isPlus) {
            cout << n << " ";
            n -= 5;
        }
        else {
            cout << n << " ";
            n += 5;
        }
        if (n <= 0) {
            isPlus = true;
            cout << n << " ";
            n += 5;
        }
    }
}
int findMax(int* arr, int length)
{
    /*
     * STUDENT ANSWER
     */
    if (length == 0) {
        return -1;
    }
    if (length == 1) {
        return arr[0];
    }
    else {
        if (arr[length - 1] > findMax(arr, length - 1)) {
            return arr[length - 1];
        }
        else {
            return findMax(arr, length - 1);
        }
    }

}
void findMax1(int* arr) {
    int temp = arr[0];
    int getArrayLength = sizeof(arr);
    for (int i = 0; i < getArrayLength; i++) {
        if (temp < arr[i]) {
            temp = arr[i];
        }
    }
    cout<< temp;
}
bool isPalindrome(const string& str) {
    if (str.empty())
       return false;
    int i = 0;
    int j = str.length() - 1;
    while (i < j){
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
bool isPalindromeRecurse(const string& str) {
    int len = str.length();
    if (len <= 1) {
        return true;
    }
    else if (str[0] != str[len - 1]) {
        return false;
    }
    else {
        cout << str.substr(1, len - 2);
        return isPalindrome(str.substr(1, len - 2));
    }
}
void printArray(int n)
{
    if (n == 0) {
        cout << "0";
    }
    else {
        printArray(n - 1);
        cout << ", " << n;
    }
}
void printArrayFor(int n) {
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            cout << "0";
        }
        else {
            cout << ", ";
            cout << i;
        }
    }
}
void printHailstone(int number){
     cout << number;
     if (number == 1) {
          return;
     }
     else if (number % 2 == 0) {
          cout << " ";
          printHailstone(number / 2);
     }
     else {
          cout << " ";
           printHailstone(number * 3 + 1);
     }
}
void printHailstoneLoop(int number) {
    cout << number; 
    while (number != 1)
    {
        if (number % 2 == 0) {
            number /= 2;
        }
        else {
            number = number * 3 + 1;
        }
        cout << " " << number;  // print the next number with a space separator
    }
}
int main() {
    // cout << isPalindrome("racecar");
    // printPattern(14);
    // int arr[] = { 10, 5, 7, 9, 15, 6, 11, 8, 12, 2 };
    // findMax1(arr);
    // cout << findMax(arr, 10);
    // printHailstone(32);
    // printArrayFor(16);
    printHailstoneLoop(32);
    return 0;
}