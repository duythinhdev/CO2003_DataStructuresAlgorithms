Class LLNode representing a node of singly linked lists is declared as below:
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
}
Given a singly linked list head node and a integer k.
Your task is to implement a function with following prototype:
LLNode* rotateLinkedList(LLNode* head, int k);
The function returns head node of the rotated singly linked list obtained after rotate the linked list to the right by k places.

Note:
- The iostream library has been used and namespace std is being used. No other libraries are allowed.
- The constructors and methods of class LLNode have been defined fully so you do not need to redefine them.
- You can write helper functions.
For example:

Test	Result
int arr[] = {2, 4, 6, 6, 3};
int k = 3;
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = rotateLinkedList(head, k);
LLNode::printList(newhead);

LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER
    if (head == nullptr || head->next == nullptr || k == 0) {
        // If the list is empty, has only one element, or k is 0, then nothing needs to be done
        return head;
    }
    int length = 1;
    LLNode* tail = head;
    while (tail->next != nullptr) {
        length++;
        tail = tail->next;
    }
    k %= length;
    if (k == 0) {
        // If k is a multiple of the length of the list, then nothing needs to be done
        return head;
    }
    LLNode* new_tail = head;
    for (int i = 0; i < length - k - 1; i++) {
        new_tail = new_tail->next;
    }
    LLNode* new_head = new_tail->next;
    new_tail->next = nullptr;
    tail->next = head;
    return new_head;
}