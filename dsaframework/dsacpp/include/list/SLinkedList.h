/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SLinkedList.h
 * Author: LTSACH
 *
 * Created on 19 August 2020, 16:56
 */

#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include "list/IList.h"

#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T> class SLinkedList;

template<class T>
class SLinkedList: public IList<T> {
public:
    class Iterator; //forward declaration
    class Node; //forward declaration
    
protected:
    Node *head; //this node does not contain user's data
    Node *tail; //this node does not contain user's data
    int  count;  //keep number of items stored in the list
    bool (*itemEqual)(T& lhs, T& rhs);
    void (*deleteUserData)(SLinkedList<T>*);
    
public:
    SLinkedList(
            void (*deleteUserData)(SLinkedList<T>*)=0, 
            bool (*itemEqual)(T&, T&)=0);
    SLinkedList(const SLinkedList<T>& list);
    SLinkedList<T>& operator=(const SLinkedList<T>& list);
    ~SLinkedList();
    
    //Inherit from IList: BEGIN
    void    add(T e);
    void    add(int index, T e);
    T       removeAt(int index);
    bool    removeItem(T item, void (*removeItemData)(T)=0);
    bool    empty();
    int      size();
    void    clear();
    T&      get(int index);
    int      indexOf(T item);
    bool    contains(T item);
    string  toString(string (*item2str)(T&)=0 );
    //Inherit from IList: BEGIN
    
    
    void println(string (*item2str)(T&)=0 ){
        cout << toString(item2str) << endl;
    }
    void setDeleteUserDataPtr(void (*deleteUserData)(SLinkedList<T>*) = 0){
        this->deleteUserData = deleteUserData;
    }

    Iterator begin(){
        return Iterator(this, true);
    }
    Iterator end(){
        return Iterator(this, false);
    }
    
    static void free(SLinkedList<T> *list){
        typename SLinkedList<T>::Iterator it = list->begin();
        while(it != list->end()){
            delete *it;
            it++;
        }
    }


protected:
    static bool equals(T& lhs, T& rhs, bool (*itemEqual)(T&, T& )){
        if(itemEqual == 0) return lhs == rhs;
        else return itemEqual(lhs, rhs);
    }
    
    void copyFrom(const SLinkedList<T>& list);
    void removeInternalData();
       
//////////////////////////////////////////////////////////////////////
////////////////////////  INNER CLASSES DEFNITION ////////////////////
//////////////////////////////////////////////////////////////////////   
public:
    class Node{
    public:
        T data;
        Node *next;
    public:
        Node(Node *next=0){
            this->next = next;
        }
        Node(T data, Node *next=0){
            this->data = data;
            this->next = next;
        }
    };
    
    //////////////////////////////////////////////////////////////////////
    //Iterator
    class Iterator{
    private:
        SLinkedList<T>* pList;
        Node* pNode;
        
    public:
        Iterator(SLinkedList<T>* pList=0, bool begin=true){
            if(begin){
                if(pList !=0) this->pNode = pList->head->next;
                else pNode = 0;
            }
            else{
                if(pList !=0) this->pNode = pList->tail;
                else pNode = 0;
            }
            this->pList = pList;
        }
        
        Iterator& operator=(const Iterator& iterator){
            this->pNode = iterator.pNode;
            this->pList = iterator.pList;
            return *this;
        }
        /*
         * remove: slow, O(n), why?
         * while-loop can have n iterations
         * => Use DLinkedList when need a linked-list
         */
        void remove(void (*removeItemData)(T)=0){
            Node* pCur = this->pList->head->next;
            Node* pPrev = this->pList->head;
            bool found = false;
            while(pCur != this->pList->tail){
                found = SLinkedList<T>::equals(pNode->data, pCur->data, pList->itemEqual);
                if(found){
                    //detach
                    pPrev->next = pCur->next;
                    if(pList->tail->next == pCur) pList->tail->next = pPrev; //update tail if needed
                    pList->count -= 1; //dec count in list
                    pCur->next = 0;

                    //remove users data + node :
                    if(removeItemData != 0) removeItemData(pCur->data);
                    delete pCur; 
                    
                    //prepare for next iteration, usually: it++
                    
                    this->pNode = pPrev;
                    
                    return;
                }
                
                //go next:
                pCur = pCur->next;
                pPrev = pPrev->next;
            }//while
        }
        
        T& operator*(){
            return pNode->data;
        }
        bool operator!=(const Iterator& iterator){
            return pNode != iterator.pNode;
        }
        // Prefix ++ overload 
        Iterator& operator++(){
            pNode = pNode->next;
            return *this; 
        }
        // Postfix ++ overload 
        Iterator operator++(int){
            Iterator iterator = *this; 
            ++*this; 
            return iterator; 
        }
    
    };
};


//////////////////////////////////////////////////////////////////////
////////////////////////     METHOD DEFNITION      ///////////////////
//////////////////////////////////////////////////////////////////////


template<class T>
SLinkedList<T>::SLinkedList(
        void (*deleteUserData)(SLinkedList<T>*), 
        bool (*itemEqual)(T&, T&) ) {
    head = new Node();
    tail = new Node();
    head->next = tail; tail->next = head;
    count = 0;
    this->itemEqual = itemEqual;
    this->deleteUserData = deleteUserData;
}

template<class T>
void SLinkedList<T>::copyFrom(const SLinkedList<T>& list){
    //Initialize this list to the empty condition
    this->count = 0;
    this->head->next = this->tail; this->tail->next = this->head;

    //Copy pointers from "list"
    this->deleteUserData = list.deleteUserData;
    this->itemEqual = list.itemEqual;

    //Copy data from "list"
    Node* ptr= list.head->next;
    while(ptr != list.tail){
        this->add(ptr->data);
        ptr = ptr->next;
    }
}

template<class T>
void SLinkedList<T>::removeInternalData(){
    //Remove user's data of this list
    if(deleteUserData != 0) deleteUserData(this);
    
    //Remove this list's data (i.e. Node)
    if((head != 0) & (tail != 0)){
        Node* ptr = head->next;
        while(ptr != tail){
            Node* next = ptr->next;
            delete ptr;
            ptr = next;
        }
    }
}
    
template<class T>
SLinkedList<T>::SLinkedList(const SLinkedList<T>& list){
    //Initialize to the empty condition
    this->head = new Node();
    this->tail = new Node();
    
    copyFrom(list);
}

template<class T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList<T>& list){
    removeInternalData();
    copyFrom(list);
            
    return *this;
}

template<class T>
SLinkedList<T>::~SLinkedList() {
    removeInternalData(); 
    
    if(head != 0) delete head;
    if(tail != 0) delete tail;
}

template<class T>
void SLinkedList<T>::add(T e) {
    Node* node = new Node(e, tail);
    tail->next->next = node;
    tail->next = node;
    count += 1;
}
template<class T>
void SLinkedList<T>::add(int index, T e) {
    if((index < 0) || (index > count))
        throw std::out_of_range("The index is out of range!");
    //index in [0, count]
    // try catch throw;
    //defind exception;
    Node* newNode = new Node(e, 0);
    Node* prevNode = head;
    int cursor = -1;

    while(cursor < index - 1){ //cursor largest = 2; index = 3
        prevNode = prevNode->next;
        cursor += 1;
    }

    //
    Node* curNode = prevNode->next;
    //Add newNode
    prevNode->next = newNode;
    newNode->next = curNode;

    //Change tail->next if needed
    if(index == count)
        tail->next = newNode;
    count += 1;
}
template<class T>
T SLinkedList<T>::removeAt(int index){
    if((index < 0) || (index > count - 1))
        throw std::out_of_range("The index is out of range!");

    //from here: index valid
    Node* prevNode = head;
    int cursor = -1;

    while(cursor < index - 1){ //cursor largest = 2; index = 3
        prevNode = prevNode->next;
        cursor += 1;
    }
    //here: prevNode points to previous item (at index - 1)
    Node* curNode = prevNode->next;
    prevNode->next = curNode->next;
    curNode->next = 0;
    if(index == (count - 1))
        tail->next = prevNode;
    count -= 1;
    return curNode->data;
}

template<class T>
bool SLinkedList<T>::removeItem(T item, void (*removeItemData)(T)){
    bool found = false;
    Node* pNode = head->next;
    Node* pPrev = head;

    while(pNode != tail){
        found = SLinkedList<T>::equals(pNode->data, item, this->itemEqual);
        if(found){
            //detachund = SLinkedList<T>::equals(pNode->data, item, this->itemEqual);
            pPrev->next = pNode->next;
            if(pNode->next == tail) tail->next = pPrev; //update tail if needed
            pNode->next = 0;
            
            //remove data
            if(removeItemData) removeItemData(pNode->data);
            delete pNode;
            this->count -= 1;
            return true;
        }
        
        pNode = pNode->next;
        pPrev = pPrev->next;
    }
    return false;
}

template<class T>
bool SLinkedList<T>::empty(){
    return count == 0;
}

template<class T>
int  SLinkedList<T>::size(){
    return count;
}

template<class T>
void SLinkedList<T>::clear(){
    removeInternalData();
    
    head->next = tail; tail->next = head;
    this->count = 0;
}

template<class T>
T& SLinkedList<T>::get(int index){
    if((index < 0) || (index > count - 1))
        throw std::out_of_range("The index is out of range!");
    //from here: index valid
    Node* prevNode = head;
    int cursor = -1;

    while(cursor < index - 1){ //cursor largest = 2; index = 3
        prevNode = prevNode->next;
        cursor += 1;
    }

    return prevNode->next->data;
}

template<class T>
int  SLinkedList<T>::indexOf(T item){
    bool found = false;
    Node* pNode = head->next;
    int foundAt = 0;

    while(pNode != tail){
        found = SLinkedList<T>::equals(pNode->data, item, this->itemEqual);
        if(found) break;
        
        pNode = pNode->next;
        foundAt += 1;
    }
    if(found) return foundAt;
    else return -1;
}
template<class T>
bool SLinkedList<T>::contains(T item){
    return indexOf(item) != -1;
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
/*
template<class T>
string SLinkedList<T>::toString(string (*item2str)(T&) ){
    stringstream ss;
    ss << "[";
    Node* ptr = head->next;
    while(ptr != tail->next){
        if(item2str != 0) ss << item2str(ptr->data) << ", ";
        else ss << ptr->data << ",";
        
        ptr = ptr->next;
    }
    
    if(count > 0)
        if(item2str != 0) ss << item2str(ptr->data) << "]";
        else ss << ptr->data << "]";
    else 
        ss << "]";
    return ss.str();
}
*/
#endif /* SLINKEDLIST_H */

