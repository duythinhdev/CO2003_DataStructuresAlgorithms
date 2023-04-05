Class BTNode is used to store a node in binary tree, described on the following:

class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};
Where val is the value of node (non-negative integer), left and right are the pointers to the left node and right node of it, respectively.

Request: Implement function:

int longestPathSum(BTNode* root);
Where root is the root node of given binary tree (this tree has between 1 and 100000 elements). This function returns the sum of the largest path from the root node to a leaf node. If there are more than one equally long paths, return the larger sum.

Example:

Given a binary tree in the following:

longestPathSum

The longest path from the root node to the leaf node is 1-4-7-4-2, so return the sum of this path, is 18.

Note: In this exercise, the libraries iostream, utility, queue, stack and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int arr[] = {-1,0,0,2,2,3,3,5};
int value[] = {1,5,4,7,12,4,8,2};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << longestPathSum(root);
18
int arr[] = {-1,0,1,0,1,4,5,3,7,3};
int value[] = {6,12,23,20,20,20,3,9,13,15};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << longestPathSum(root);
61


int longestPathSumHelper(BTNode* root, int parentSum, int& maxSum) {
    if (!root) return 0;
    int currentSum = parentSum + root->val;
    if (!root->left && !root->right) {
        maxSum = max(maxSum, currentSum);
    } else {
        longestPathSumHelper(root->left, currentSum, maxSum);
        longestPathSumHelper(root->right, currentSum, maxSum); 
    }
    return maxSum; 
}
int longestPathSum(BTNode* root) {
    int maxSum = 0;
    longestPathSumHelper(root, 0, maxSum);
    return maxSum;
}