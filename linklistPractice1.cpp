// Implement methods add, size in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.

For example:

Test	Result
SLinkedList<int> list;
int size = 10;

for(int index = 0; index < size; index++){
    list.add(index);
}

cout << list.toString();
[0,1,2,3,4,5,6,7,8,9]
SLinkedList<int> list;
int size = 10;

for(int index = 0; index < size; index++){
    list.add(0, index);
}

cout << list.toString();
[9,8,7,6,5,4,3,2,1,0]

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void add(T e){
      Node* pN = new Node(e);
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
    void add(int index, T e){
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
    }
    int size(){
    	return count;
    }
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