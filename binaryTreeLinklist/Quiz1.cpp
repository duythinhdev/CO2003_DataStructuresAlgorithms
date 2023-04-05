Given a Binary tree, the task is to count the number of nodes with two children
#include<iostream>
#include<string>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if(posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }

    // STUDENT ANSWER BEGIN
    // STUDENT ANSWER END
};
You can define other functions to help you.

For example:

Test	Result
BinaryTree<int, int> binaryTree;
binaryTree.addNode("",2, 4); // Add to root
binaryTree.addNode("L",3, 6); // Add to root's left node
binaryTree.addNode("R",5, 9); // Add to root's right node
cout << binaryTree.countTwoChildrenNode();
1
BinaryTree<int, int> binaryTree;
binaryTree.addNode("",2, 4);
binaryTree.addNode("L",3, 6);
binaryTree.addNode("R",5, 9);
binaryTree.addNode("LL",4, 10);
binaryTree.addNode("LR",6, 2);
cout << binaryTree.countTwoChildrenNode();
2

// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

int countTwoChildrenNode()
{
   return countTwoChildrenNode(root);
}

private:
    int countTwoChildrenNode(Node* node)
    {
        if (!node)
            return 0;

        int count = 0;
        if (node->pLeft && node->pRight)
            count++;

        count += countTwoChildrenNode(node->pLeft);
        count += countTwoChildrenNode(node->pRight);

        return count;
    }
// STUDENT ANSWER END