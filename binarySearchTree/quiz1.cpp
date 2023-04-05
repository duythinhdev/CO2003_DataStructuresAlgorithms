In this question, you have to perform add and delete on binary search tree. Note that:

- When deleting a node which still have 2 children, take the inorder successor (smallest node of the right sub tree of that node) to replace it.

- When adding a node which has the same value as parent node, add it in the left sub tree.

Your task is to implement two functions: add and deleteNode. You could define one or more functions to achieve this task.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
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

    //Helping function

    void add(T value){
        //TODO
    }
   
    void deleteNode(T value){
        //TODO
    }
    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder(){
        return inOrderRec(this->root);
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
};

For example:

Test	Result
BinarySearchTree<int> bst;
bst.add(9);
bst.add(2);
bst.add(10);
bst.deleteNode(9);
cout << bst.inOrder();
2 10 
BinarySearchTree<int> bst;
bst.add(9);
bst.add(2);
bst.add(10);
bst.add(8);
cout << bst.inOrder()<<endl;
bst.add(11);
bst.deleteNode(9);
cout << bst.inOrder();
2 8 9 10 
2 8 10 11 


void add(T value){
    //TODO
    Node *newNode = new Node(value);
    if (root == nullptr){
        root = newNode;
        return;
    }
    Node *current = root;
    Node *parent = nullptr;
    while (current != nullptr){
        parent = current;
        if (newNode->value < current->value)
            current = current->pLeft;
        else
            current = current->pRight;
    }
    if (newNode->value < parent->value)
        parent->pLeft = newNode;
    else
        parent->pRight = newNode;
    
}

void deleteNode(T value){
    //TODO
      Node *parent = nullptr;
    Node *current = root;
    while (current != nullptr && current->value != value){
        parent = current;
        if (value < current->value)
            current = current->pLeft;
        else
            current = current->pRight;
    }
    if (current == nullptr) // not found
        return;
    if (current->pLeft == nullptr){ // Case 1: no left child
        if (parent == nullptr) // deleting the root node
            root = current->pRight;
        else if (current == parent->pLeft)
            parent->pLeft = current->pRight;
        else
            parent->pRight = current->pRight;
        delete current;
    } else if (current->pRight == nullptr){ // Case 2: no right child
        if (parent == nullptr) // deleting the root node
            root = current->pLeft;
        else if (current == parent->pLeft)
            parent->pLeft = current->pLeft;
        else
            parent->pRight = current->pLeft;
        delete current;
    } else { // Case 3: two children
        Node *successorParent = current;
        Node *successor = current->pRight;
        while (successor->pLeft != nullptr){
            successorParent = successor;
            successor = successor->pLeft;
        }
        current->value = successor->value;
        if (successor == successorParent->pLeft)
            successorParent->pLeft = successor->pRight;
        else
            successorParent->pRight = successor->pRight;
        delete successor;
    }
}