Class BSTNode is used to store a node in binary search tree, described on the following:

class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
};
Where val is the value of node, left and right are the pointers to the left node and right node of it, respectively. If a repeated value is inserted to the tree, it will be inserted to the left subtree.

Request: Implement function:

int kthSmallest(BSTNode* root, int k);
Where root is the root node of given binary search tree (this tree has n elements) and k satisfy: 1 <= k <= n <= 100000. This function returns the k-th smallest value in the tree.

Example:

Given a binary search tree in the following:

minimum
With k = 2, the result should be 1.

Note: In this exercise, the libraries iostream, vector, stack, queue, algorithm, climits and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int arr[] = {6, 9, 2, 13, 0, 20};
int k = 2;
BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr)/sizeof(int));
cout << kthSmallest(root, k);
BSTNode::deleteTree(root);
2
int kthSmallest(BSTNode* root, int k) {
    // STUDENT ANSWER
    int count = 0;
    stack<BSTNode*> s;
    BSTNode* curr = root;
    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        count++;
        if (count == k) {
            return curr->val;
        }
        curr = curr->right;
    }
    return -1; // k is larger than the number of nodes in the tree
}