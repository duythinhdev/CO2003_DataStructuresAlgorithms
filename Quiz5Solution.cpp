Given the following types:

typedef struct Item* ptr;

struct Item

{

    double coef; // coefficient

    int exp; // exponent

    ptr next;

}

This struct is used to keep an element aixi where coef keeps ai and exp keeps i in a polynomial Pn(x) = anxn +an-1xn-1+...+a0x0

Write function inputPolynomial() that inputs from stdin a polynomial and returns the linked list of input values in reversed order. Each item including the coefficient ai and the exponent i is input in one line. The input is terminated when 0 is input for the coefficient.

Your code starts at line 20.

ptr inputPolynomial() {
    ptr p = NULL;
    struct Item v;
    cin >> v.coef >> v.exp;
    while (v.coef != 0) {
        ptr q = new Item;
        q->coef = v.coef;
        q->exp = v.exp;
        q->next = p;
        p = q;
        cin >> v.coef >> v.exp;
    }
    return p;
}