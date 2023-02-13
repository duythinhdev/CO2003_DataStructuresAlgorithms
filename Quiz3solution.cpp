Given the following types:

typedef struct Item* ptr;

struct Item

{

    int value;

    ptr next;

}

Write function inputList() that inputs from stdin a sequence of non-negative integer numbers until meeting a negative value and returns the linked list of input values (excluding the negative value) in reversed order. 

Your code starts at line 20.
ptr inputList() {
    ptr p = NULL;
    int v;
    cin >> v;
    while (v >= 0) {
        ptr q = new Item;
        q->value = v;
        q->next = p;
        p = q;
        cin >> v;
    }
    return p;
}