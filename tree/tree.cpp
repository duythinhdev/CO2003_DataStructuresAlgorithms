#include<iostream>;
#include<conio.h>;

using namespace std;

struct node {
    int key;
    node *left;
    node *right;
};

void init(node *&root) {
    root = NULL;
}

node *createNode(int x) {
    node *p = new node;
    p->key = x;
    p->left = NULL;
    p->right = NULL;
}

void insertNode(node *&root, int x) {
    if (root == NULL) {
        root = createNode(x);
    } else {
        // tim vi tri can chen
        node *p = root;
        node *parent = NULL;
        while (p != NULL && p->key != x) {
            parent = p;
            if (p->key > x) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
        // thuc hien chen
        if (p == NULL) {
            p = createNode(x);
            if (parent->key < x) {
                parent->right = p;
            } else {
                parent->left = p;
            }
        }
    }
}

void lnr(node *root) {
    if (root != NULL) {
        lnr(root->left);
        cout << root->key << "\t";
        lnr(root->right);
    }
}

node *search(node *root, int x) {
    // tim vi tri can chen
    node *p = root;
    while (p != NULL && p->key != x) {
        if (p->key > x) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return p;
    // thuc hien chen
}

int main() {
    node *root;
    init(root);
    insertNode(root, 15);
    insertNode(root, 20);
    insertNode(root, 8);
    insertNode(root, 40);
    insertNode(root, 12);
    insertNode(root, 90);
    lnr(root);
    if(search(root,90) != NULL){
        cout << "Tim thay 90" << "\n";
    } else {
        cout << "Khong Tim thay 90" << "\n";
    }
    if(search(root,99) != NULL){
        cout << "Tim thay 99" << "\n";
    } else {
        cout << "Khong Tim thay 99" << "\n";
    }
    return 0;
}