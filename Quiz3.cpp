Given the following types:

typedef struct Item* ptr;

struct Item

{

    int value;

    ptr next;

}

Write function inputList() that inputs from stdin a sequence of non-negative integer numbers until meeting a negative value and returns the linked list of input values (excluding the negative value) in reversed order. 

Your code starts at line 20.
#include <iostream>

ptr inputList() {
    ptr head = nullptr;
    int val;
    std::cin >> val;
    while (val >= 0) {
        ptr temp = new Item;
        temp->value = val;
        temp->next = head;
        head = temp;
        std::cin >> val;
    }
    return head;
}