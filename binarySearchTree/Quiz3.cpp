Given class BinarySearchTree, you need to finish method find(i) to check whether value i is in the tree or not; method sum(l,r) to calculate sum of all all elements v in the tree that has value greater than or equal to l and less than or equal to r.

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
    cout << bst.find(7) << endl;
    cout << bst.sum(0, 4) << endl
1
10
bool find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
    Node* current = root;
      while (current != nullptr) {
        if (current->value == i) {
            return true;
        } else if (current->value > i) {
            current = current->pLeft;
        } else {
            current = current->pRight;
        }
    }
    return false;
}

T sumT(Node* node, T l, T r) {
    if (node == nullptr) {
        return 0;
    }
    if (node->value < l) {
        return sumT(node->pRight, l, r);
    }
    if (node->value > r) {
        return sumT(node->pLeft, l, r);
    }
    return node->value + sumT(node->pLeft, l, r) + sumT(node->pRight, l, r);
}
T sum(T l, T r) {
    // TODO: return the sum of all element in the tree has value in range [l,r].
    return sumT(root, l, r);
}

// STUDENT ANSWER END