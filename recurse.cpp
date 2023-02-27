#include<iostream>
#include<conio.h>
#include<string>
#include<regex>
#include<string.h>
#include <string>
#include <sstream>
using namespace std;

void printPattern(int n) {
    bool isPlus = false;
    int lon = n;
    for (int i = 0; i < lon; i++) {
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
    cout << temp;
}
bool isPalindrome(const string& str) {
    if (str.empty())
        return false;
    int i = 0;
    int j = str.length() - 1;
    while (i < j) {
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
void printHailstone(int number) {
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
    // cout << number;
    while (number != 1) {
        if (number % 2 == 0) {
            number /= 2;
        }
        else {
            number = number * 3 + 1;
        }
        cout << " " << number;
    }
}
int myArrayToInt(char* str, int n) {
    int num = 0;
    int digit;
    int i = 0;
    while (i < n) {
        digit = (int)(str[i] - '0');
        num = num * 10 + digit;
        i++;
    }
    return num;
}
int myArrayToIntRecurse(char* str, int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return myArrayToIntRecurse(str, n - 1) * 10 + (str[n - 1] - '0');
    }
}
int strLen(char* str) {
    // int newString = sizeof(str);
   // int count = 0; 
   // for (int i = 0; i < newString; i++) {
       // count++;
   // }
   // return count;
    int len;
    for (len = 0; str[len] != '\0'; len++);
    return len;
}
int strLenRecurse(char* str) {
    if (*str == '\0') {
        return 0;
    }
    else {
        return 1 + strLen(str + 1);
    }
}
string reverseSentence(string s) {
    // Use a stringstream to split the sentence into words
    stringstream ss(s);
    string word;
    string reversedSentence;

    // Read each word from the stringstream and prepend it to the reversed sentence
    while (ss >> word) {
        reversedSentence = word + " " + reversedSentence;
    }

    // Remove the trailing space character and return the reversed sentence
    if (!reversedSentence.empty()) {
        reversedSentence.pop_back();
    }
    return reversedSentence;
}
int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int findLCM(int a, int b) {
    int lcm = (a * b) / gcd(a, b);
    return lcm;
}
int mininumBracketAdd(string s) {
    int bal = 0;
    int ans = 0;

    for (int i = 0; i < s.length(); ++i) {

        bal += s[i] == '(' ? 1 : -1;

        // It is guaranteed bal >= -1
        if (bal == -1) {
            ans += 1;
            bal += 1;
        }
    }

    return bal + ans;
}

int countOpening(std::string s, int i) {
    if (i == s.length()) {
        return 0;
    }
    int count = s[i] == '(' ? 1 : -1;
    if (count < 0) {
        return 1 + countOpening(s, i + 1);
    }
    return count + countOpening(s, i + 1);
}

int countClosing(std::string s, int i) {
    if (i == -1) {
        return 0;
    }
    int count = s[i] == ')' ? 1 : -1;
    if (count < 0) {
        return 1 + countClosing(s, i - 1);
    }
    return count + countClosing(s, i - 1);
}

int minimumBracketAddRecurse(std::string s) {
    int openingCount = countOpening(s, 0);
    int closingCount = countClosing(s, s.length() - 1);
    return openingCount + closingCount;
}
int main() {
    // cout << isPalindrome("racecar");
    // printPattern(14);
    // int arr[] = { 10, 5, 7, 9, 15, 6, 11, 8, 12, 2 };
    // findMax1(arr);
    // cout << findMax(arr, 10);
    // printHailstone(32);
    // printArrayFor(16);
    // printHailstoneLoop(32);
    // char str[] = "2027";
    // cout << myArrayToIntRecurse(str, 4);
    // char str[] = "";
    // cout << strLenRecurse(str);
    // string s = "Hello world, this is a sentence.";
    // string reversed = reverseSentence(s);
    // cout << reversed;
    // cout << findLCM(10, 102);
    cout << minimumBracketAddRecurse(")))((");
    return 0;
}