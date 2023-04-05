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

int lowestAncestor(BTNode* root, int a, int b);
Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the lowest ancestor node's val of node a and node b in this binary tree (assume a and b always exist in the given binary tree).

More information:

- A node is called as the lowest ancestor node of node a and node b if node a and node b are its descendants.

- A node is also the descendant of itself.

- On the given binary tree, each node's val is distinguish from the others' val

Example:

Given a binary tree in the following:

LowestAncestor

- The lowest ancestor of node 4 and node 5 is node 2.

Note: In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int arr[] = {-1,0,0,2,2,3,3};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), NULL);
cout << lowestAncestor(root, 4, 5);
2
int arr[] = {-1,0,1,1,0,4,4,2,5,6};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), NULL);
cout << lowestAncestor(root, 4, 9);
4

int lowestAncestor(BTNode* root, int a, int b) {
     if (root == NULL) {
        return -1; // if root is null, return an invalid value
    }
    if (root->val == a || root->val == b) {
        return root->val; // if a or b is found, return root value
    }
    int left = lowestAncestor(root->left, a, b); // search left subtree
    int right = lowestAncestor(root->right, a, b); // search right subtree
    if (left != -1 && right != -1) {
        return root->val; // if a is in left subtree and b is in right subtree, or vice versa, return root value
    } else if (left != -1) {
        return left; // if a and b are both in the left subtree, return lowest ancestor value in the left subtree
    } else {
        return right; // if a and b are both in the right subtree, return lowest ancestor value in the right subtree
    }
}