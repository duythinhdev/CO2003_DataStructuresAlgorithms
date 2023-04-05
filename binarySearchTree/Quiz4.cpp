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

vector<int> levelAlterTraverse(BSTNode* root);
Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). This function returns the values of the nodes in each level, alternating from going left-to-right and right-to-left..

Example:

Given a binary search tree in the following:

levelAlter
In the first level, we should traverse from left to right (order: 3) and in the second level, we traverse from right to left (order: 4, 0). After traversing all the nodes, the result should be [3, 4, 0, 2, 1].

Note: In this exercise, the libraries iostream, vector, stack, queue, algorithm and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int arr[] = {0, 3, 5, 1, 2, 4};
BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr)/sizeof(int));
printVector(levelAlterTraverse(root));
BSTNode::deleteTree(root);
[0, 3, 1, 5, 4, 2]
vector<int> levelAlterTraverse(BSTNode* root) {
    // STUDENT ANSWER
     vector<int> result;
    if (root == nullptr) {
        return result;
    }
    
    queue<BSTNode*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int levelSize = q.size();
        stack<int> s;
        for (int i = 0; i < levelSize; i++) {
            BSTNode* curr = q.front();
            q.pop();
            if (leftToRight) {
                result.push_back(curr->val);
            } else {
                s.push(curr->val);
            }
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        leftToRight = !leftToRight;
    }
    return result;
}