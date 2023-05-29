#include<conio.h>
#include<iostream>
using namespace std;


template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* node = new Node(e);
    if(head == NULL){
        head = node;
        tail = node;
    }else{
        tail->next = node;
        node->previous = tail;
        tail = node;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    if (index < 0 || index > count) {
        throw out_of_range("Index out of range");
    }
    if (index == count) {
        add(e);
        return;
    }
    Node* newNode = new Node(e);
    if(index == 0){
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }else {
        Node* current = head;
        for(int i = 0; i < index;i++){
            current = current->next;
        }
        newNode->next = current;
        newNode->previous = current->previous;
        current->previous->next = newNode;
        current->previous = newNode;
    }
    count++;
}
