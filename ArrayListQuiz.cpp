#include<iostream>;
#include<conio.h>;
#include<vector>;
using namespace std;

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
int buyCar(int* nums, int length, int k) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (k % nums[i] == 0) {
			count++;
		}
	}
	return count;
}
int main() {
	// vector<int> nums{ 13, 0, 6, 9, 14, 16 };
	// vector<vector<int>> operations{ {5, 5, 16}, {3, 4, 0}, {0, 2, 8} };
	// printVector(updateArrayPerRange(nums, operations));
	// vector<int> nums{ 0, 1, 1, 1, 9, 8 };
	// cout << consecutiveOnes(nums);
	int nums[100] = { 90,30,40,90,20 };
	int length = sizeof(nums) / sizeof(nums[0]);
    cout << buyCar(nums, length, 90) << "\n";
	return 0;
}