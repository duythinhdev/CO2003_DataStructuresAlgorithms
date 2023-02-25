class DoubleLinkedList {
private:
 TwoWayNode* pHead;
 int count;
public:
 DoubleLinkedList() {
 pHead = NULL;
 count = 0;
 }
 void prepend(int data) {
 TwoWayNode* pNew = new TwoWayNode();
 pNew->data = data;
 pNew->prev = NULL;
 pNew->next = pHead;
 pHead = pNew;
 return;
 }
 void insert(int data, int idx) {
 if (idx > count) {
 cout << "Index is out of range." << endl;
 return;
 }
 if (idx == 0) {
 prepend(data);
 } else {
 TwoWayNode* pNew = new TwoWayNode();
 pNew->data = data;
 TwoWayNode* pTemp = pHead;
 for (int i = 0; i < idx - 1; i++) {
 pTemp = pTemp->next;
 }
 pNew->next = pTemp->next;
 pNew->prev = pTemp;
 pTemp->next = pNew;
 if (idx == 0) {
 pHead = pTemp;
 }
 }
 count++;
 return;
 }
 void remove(int target) {
 TwoWayNode *pTemp = pHead;
 TwoWayNode *pDel = NULL;
 while (pTemp != NULL) {
 if (pTemp->data == target) {
 pTemp->prev->next = pTemp->next;
 pDel = pTemp;
 pTemp = pTemp->next;
 delete pDel;
 } else {
 pTemp = pTemp->next;
 }
 }
 return;
 }
 ~DoubleLinkedList() {
 TwoWayNode* pTemp = pHead;
 while (pTemp != NULL) {
 pTemp = pTemp->next;
 delete pHead;
 pHead = pTemp;
 }
 }
void reverse() {
 TwoWayNode* pCurrent = pHead;
 TwoWayNode* pTemp = NULL;
 while (pCurrent != NULL) {
 pTemp = pCurrent->prev;
 pCurrent->prev = pCurrent->next;
 pCurrent->next = pTemp;
 pCurrent = pCurrent->prev;
 }
 if (pTemp != NULL) {
 pHead = pTemp->prev;
 }
 return;
 }
};
int main() {
 cout << "Question 1:" << endl;
 SingleLinkedList L1;
 int q1[10] = { 7, 8, 4, 13, 10, 7, 5, 6, 9, 1 };
 for (int i = 0; i < 10; i++) {
    L1.prepend(q1[i]);
 }
 // L2 = {1, 3, 2, 5, 6}
 // L2.insert(4, 2) // data = 4, idx = 2
 // L2 = {1, 3, 4, 2, 5, 6}
 // L3 = {1, 3, 2, 5, 6}
 // Node *target = L3.search(5)
 // target->data is 5
 // L4 = {1, 3, 2, 5, 6}
 // L4.remove(3)
 // L4 = {1, 2, 5, 6}
 // L5a = {1, 4, 7}
 // L5b = {9, 6, 5}
 // L5a.extend(L5b)
 // L5a = {1, 4, 7, 9, 6, 5}
 // L5b = {9, 6, 5}
 // L7 = {1, 3, 2, 5, 6}
 // L7.reverse()
 // L7 = {6, 5, 3, 2, 1}

 L1.display();
}
