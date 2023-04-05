Given class BinarySearchTree, you need to finish method getMin() and getMax() in this question.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<class T>
class BinarySearchTree
{
public:
    class Node;

private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;

    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node* addRec(Node* root, T value);
    void add(T value) ;
    // STUDENT ANSWER BEGIN
 
    // STUDENT ANSWER END
};



For example:

Test	Result
BinarySearchTree<int> bst;
for (int i = 0; i < 10; ++i) {
    bst.add(i);
}
cout << bst.getMin() << endl;
cout << bst.getMax() << endl;
0
9
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

T getMin() {
    //TODO: return the minimum values of nodes in the tree.
     Node* cur = root;
    while (cur->pLeft != nullptr) {
        cur = cur->pLeft;
    }
    return cur->value;
}

T getMax() {
    //TODO: return the maximum values of nodes in the tree.
    Node* cur = root;
    while (cur->pRight != nullptr) {
        cur = cur->pRight;
    }
    return cur->value;
}

// STUDENT ANSWER END