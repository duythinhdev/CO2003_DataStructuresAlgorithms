Given the following types:

typedef struct Item* ptr;

struct Item

{

    double coef; // coefficient

    int exp; // exponent

    ptr next;

}

This struct is used to keep an element aixi where coef keeps ai and exp keeps i in a polynomial Pn(x) = anxn +an-1xn-1+...+a0x0

Write function void normalizePolynomial(ptr& first) that normalizes the polynomial first and returns the linked list of normalized polynomial. The input polynomial is normalized as follows:

- if there are many elements with the same exponent, just keep the last input element whose coefficient is the sum of these coefficients and remove all other elements with the same exponent. If the sum of coefficient of the elements is zero, remove all these elements.

For example, if the input is as follows: (-1,2) (-1,1) (1,2) (1,3) (2,1) where (2,1) is the last input. The result is (1,1) (1,3) where (1,3) is the last printed value.

Your code starts at line 20.

void normalizePolynomial(ptr &first) {
    ptr head = new Item;
    head->next = first;
    ptr calculated = first;
    ptr previous = head;
    while (calculated != NULL) {
        ptr pre = calculated;
        ptr curr = calculated->next;
        while (curr != NULL) {
                 if (curr->exp == calculated->exp) {
                     calculated->coef += curr->coef;
                     curr = curr->next;
                     delete pre->next;
                     pre->next = curr;
                 } else {
                     pre = curr; 
                     curr = curr->next;
                 }
             }
        if (calculated->coef == 0) {
            calculated = calculated -> next;
            delete previous->next;
            previous->next = calculated;
        } else {
            previous = calculated;
            calculated = calculated -> next;
        }
    }
    first = head->next;
    delete head;
}