In the previous implementation of function infix_cal, a nested if would be used to compare the input operator with expected operators like "+", "-",... This approach requires changing the nested if when there are more operators. 

In this exercise, the function must not use such a nested if but it must use a loop over an array that contains a struct of an operator string and a function pointer.

Assume that the following definitions have been declared for your usage:

struct action {

    string op; // operator

    int (*func)(int, int); // function pointer to corresponding function

};

int myadd(int x, int y) { return x + y;}

int mymin(int x, int y) { return x - y;}

int mymul(int x, int y) { return x * y;}

int mydiv(int x, int y) { return x / y;}

Your code starts at line 20.
action ope[4] = {{"+",&myadd},{"-",&mymin},{"*",&mymul},{"/",&mydiv}};
int infix_cal(const string& input) {
    size_t pos = input.find(" ",0);
    string op1,op2,op;
    op1 = input.substr(0,pos);
    op = input.substr(pos + 1,1);
    op2 = input.substr(pos + 3);
    int val1 = stoi(op1);
    int val2 = stoi(op2);
    for (int i = 0; i < 3; i++) 
        if (op.compare(ope[i].op)==0)
            return (ope[i].func)(val1,val2);
    return (ope[3].func)(val1,val2);
}
    
   