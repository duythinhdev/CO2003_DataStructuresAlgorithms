Class BTNode is used to store a node in binary search tree, described on the following:

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

int rangeCount(BTNode* root, int lo, int hi);
Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements), lo and hi are 2 positives integer and lo ≤ hi. This function returns the number of all nodes whose values are between [lo, hi] in this binary search tree.

More information:

- If a node has val which is equal to its ancestor's, it is in the right subtree of its ancestor.

Example:

Given a binary search tree in the following:

RangeCount

With lo=5, hi=10, all the nodes satisfied are node 9, 7, 8; there fore, the result is 3.

Note: In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int value[] = {3,2,9,7,12,4,8};
int lo = 5, hi = 10;
BTNode* root = BTNode::createBSTree(value, value + sizeof(value)/sizeof(int));
cout << rangeCount(root, lo, hi);
3
int value[] = {1167,2381,577,2568,124,1519,234,1679,2696,2359};
int lo = 500, hi = 2000;
BTNode* root = BTNode::createBSTree(value, value + sizeof(value)/sizeof(int));
cout << rangeCount(root, lo, hi);
4

int rangeCount(BTNode* root, int lo, int hi) {
    if (!root) {
        return 0;
    }
    if (root->val < lo) {
        return rangeCount(root->right, lo, hi);
    }
    if (root->val > hi) {
        return rangeCount(root->left, lo, hi);
    }
    return 1 + rangeCount(root->left, lo, hi) + rangeCount(root->right, lo, hi);
}