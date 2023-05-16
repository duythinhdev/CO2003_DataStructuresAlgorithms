#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>

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
    void addOne(const T &e);
    void add(int index, const T &e);
    int size();
    T removeAt(int index);
    T removeItem(const T &e);
    string  toString(string (*item2str)(T&)=0 );
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

    void clear();
};

template <class T>
//void SLinkedList<T>::addOne(const T& e) {
//    Node* pN = new Node(e, NULL);
//    if (count == 0) {
//        head = tail = pN;
//        ++count;
//    }
//    else {
//        tail->next = pN;
//        tail = pN;
//        ++count;
//    }
//}
void SLinkedList<T>::addOne(const T& e) {
    Node* pN = new Node(e, NULL);
    if(count == 0){
        head = tail = pN;
        ++count;
    }else {
        tail->next = pN;
        tail = pN;
    }
}
template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    if(index < 0 || index > count ){
        throw "Index out of bounds";
    }
    Node* newNode = new Node(e, NULL);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    } else if(index == 0){
        newNode->next = head;
        head = newNode;
    } else if(index == count){
         tail->next = newNode;
         tail = newNode;
    } else {
        Node* current = head;
        for(int i  = 0 ; i < index - 1; i ++){
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
template<class T>
T SLinkedList<T>::removeAt(int index) {
    if(index < 0 || index >= count ){
        throw out_of_range("Index out of range");
    }
    Node* temp = head;
    Node* prev = NULL;
    for(int i = 0; i < index;i ++){
        prev = temp;
        temp = temp->next;
    }
    if(prev == nullptr){
        head = prev->next;
    }else {
        prev->next = temp->next;
    }if(tail == temp){
        tail = prev;
    }
    T data = temp->data;
    delete temp;
    count--;
    return data;
}
template<class T>
T SLinkedList<T>::removeItem(const T& item){
    Node* curr = head;
    Node* prev = NULL;
    while(curr != nullptr){
        if(curr->data == item) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            if (curr == tail) {
                tail = prev;
            }
            delete curr;
            count--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}
template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (head != nullptr){
        Node* curr = head;
        curr = curr->next;
        delete curr;
    }
    tail = nullptr;
    count = 0;
}
template<class T>
string SLinkedList<T>::toString(string (*item2str)(T&) ){
    if(this->count <= 0) return "[]";

    stringstream itemos;
    Node* ptr = head->next;
    while(ptr != tail){
        if(item2str != 0) itemos << item2str(ptr->data) << ", ";
        else itemos << ptr->data << ", ";

        ptr = ptr->next;
    }
    //remove the last ", "
    string itemstr = itemos.str();
    itemstr = itemstr.substr(0, itemstr.rfind(','));
    return "[" + itemstr + "]";
}


int main(){
    SLinkedList<int> list;
    int size = 10;

    for(int index = 0; index < size; index++){
        list.add(0, index);
        list.addOne(index);
    }
    cout << list.toString();
    return 0;
}