#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
template <class T>
class SLinkedList {
public:
    class Node;
protected:
    Node* head;
    Node* tail;
    int count;
public:
//    SLinkedList();
//    ~SLinkedList();
    void addOne(const T &e);
    void add(int index, const T &e);
    int size();
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void SLinkedList<T>::addOne(const T& e) {
    Node* pN = new Node(e, NULL);
    if (count == 0) {
        head = tail = pN;
        ++count;
    }
    else {
        tail->next = pN;
        tail = pN;
        ++count;
    }
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /*Insert an element into the list at given index.*/
    if (index < 0 || index > count) {
        throw "Index out of bounds";
    }
    Node* newNode = new Node(e, NULL);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else if (index == 0) {
        newNode->next = head;
        head = newNode;
    }
    else if (index == count) {
        tail->next = newNode;
        tail = newNode;
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    count++;
}

template<class T>
int SLinkedList<T>::size() {
    return count;
}


int main(){
    SLinkedList<int> list;
    int size = 10;

    for(int index = 0; index < size; index++){
        list.add(0, index);
        list.addOne(index);
    }
    cout << &list;
    return 0;
}