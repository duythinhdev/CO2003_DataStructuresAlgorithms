Implement methods removeAt, removeItem, clear in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.

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
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    int     size();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
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
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};

For example:

Test	Result
SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.get(0) == list.removeAt(0));

    cout << list.toString();
[1,2,3,4,5,6,7,8,9]
    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.get(9) == list.removeAt(9));

    cout << list.toString();
[0,1,2,3,4,5,6,7,8]
    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.removeItem(9));

    cout << list.toString();
[0,1,2,3

template <class T>
T SLinkedList<T>::removeAt(int index){
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }
    Node* temp = head;
    Node* prev = NULL;
    for (int i = 0; i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    if (tail == temp) {
        tail = prev;
    }
    T data = temp->data;
    delete temp;
    count--;
    return data;
    /* Remove element at index and return removed value */
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (curr->data == item) {
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
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    count = 0;
}

