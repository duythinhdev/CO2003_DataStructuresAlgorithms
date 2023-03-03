#include<iostream>;
#include<conio.h>;
#include<vector>;
#include<functional>;
#include<numeric>;
using namespace std;
// Given an array of integers nums and a two - dimension array of integers operations.
// Each operation in operations is represented in the form{ L, R, X }. When applying an operation, all elements with index in range[L, R](include Land R) increase by X.
// Your task is to implement a function with following prototype :
// vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations);
// The function returns the array after applying all operation in operations.
//
// Note:
// -The iostream, and vector libraries have been includedand namespace std is being used.No other libraries are allowed.
// - You can write helper functions.
vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
	vector<int> result = nums;
	for (vector<int>& operation : operations) {
		int l = operation[0];
		int r = operation[1];
		int x = operation[2];
		for (int i = l; i <= r; i++) {
			result[i] += x;
		}
	}
	return result;
}
//Given an array of integers.
//Your task is to implement a function with the following prototype :
//bool consecutiveOnes(vector<int> & nums);
//The function returns if all the 1s appear consecutively in nums.If nums does not contain any elements, please return true
//
//Note:
//-The iostream and vector libraries have been included and namespace std are being used.No other libraries are allowed.
//- You can write helper functions.
//- Do not use global variables in your code.
bool consecutiveOnes(vector<int>& nums) {
	bool foundOne = false;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			if (!foundOne) {
				foundOne = true;
			}
			else if (i > 0 && nums[i-1] != 1) {
				foundOne = false;
			}
			else {
				foundOne = false;
			}
		}
	}
	return true;
}
// The prices of all cars of a car shop have been saved as an array called N.Each element of the array N is the price of each car in shop.A person, with the amount of money k want to buy as much cars as possible.
// Request: Implement function
// buyCar(int* nums, int length, int k);
// Where nums is the array N, length is the size of this arrayand k is the amount of money the person has.Find the maximum cars this person can buy with his money, and return that number.
// Example:
// nums = [90, 30, 20, 40, 50]; k = 90;
// The result is 3, he can buy the cars having index 1, 2, 3 (first index is 0).
// Note: The library iostream, 'algorithm' and using namespace std have been used.You can add other functions but you are not allowed to add other libraries.
int buyCar(int* nums, int length, int k) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (k % nums[i] == 0) {
			count++;
		}
	}
	return count;
}
// Given an array of strings.
// Your task is to implement a function with following prototype :
// int longestSublist(vector<string>& words);
// The function returns the length of the longest subarray where all words share the same first letter.
//
// Note:
// -The iostream and vector libraries have been included and namespace std is being used.No other libraries are allowed.
// - You can write helper functions.
int longestSublist(vector<string>& words) {
	// STUDENT ANSWER
	int longestLength = 0;
	int currentLength = 0;
	char currentFirstLetter = '\0';
	for (const auto& word : words) {
		if (word.empty()) {
			continue;
		}
		if (word[0] != currentFirstLetter) {
			longestLength = max(longestLength, currentLength);
			currentLength = 1;
			currentFirstLetter = word[0];
		}
		else {
			currentLength++;
		}
	}
	longestLength = max(longestLength, currentLength);
	return longestLength;
}
//Given an array of integers.
//Your task is to implement a function with following prototype :
//int equalSumIndex(vector<int>& nums);
//The function returns the smallest index i such that the sum of the numbers to the left of i is equal to the sum of the numbers to the right.
//If no such index exists, return -1.
//
//Note:
//-The iostream and vector libraries have been included and namespace std is being used.No other libraries are allowed.
//- You can write helper functions.
int equalSumIndex(vector<int>& nums) {
	// STUDENT ANSWER
	//int leftSum = 0;
	//int rightSum = accumulate(nums.begin(), nums.end(), 0);
	//for (int i = 0; i < nums.size(); i++) {
	//	rightSum -= nums[i];
	//	if (leftSum == rightSum) {
	//		return i;
	//	}
	//	leftSum += nums[i];
	//	cout << "leftSum" << leftSum;
	//}

	//return -1;

	int leftSum = 0;
	int rightSum = accumulate(nums.begin(), nums.end(),0);
	for (int i = 0; i < nums.size(); i++) {
		rightSum -= nums[i];
		if (leftSum == rightSum) {
			return i;
		}
		leftSum += nums[i];
	}
	return -1;
}
int main() {
	// vector<int> nums{ 13, 0, 6, 9, 14, 16 };
	// vector<vector<int>> operations{ {5, 5, 16}, {3, 4, 0}, {0, 2, 8} };
	// printVector(updateArrayPerRange(nums, operations));
	// vector<int> nums{ 0, 1, 1, 1, 9, 8 };
	// cout << consecutiveOnes(nums);
	// int nums[100] = { 90,30,40,90,20 };
	// int length = sizeof(nums) / sizeof(nums[0]);
    // cout << buyCar(nums, length, 90) << "\n";
	// vector<string> words{ "faction", "fight", "and", "are", "attitude" };
	// cout << longestSublist(words);
	vector<int> nums{ 3, 5, 2, 7, 6, 4 };
	cout << equalSumIndex(nums);
	return 0;
}