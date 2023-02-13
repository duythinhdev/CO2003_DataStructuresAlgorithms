Write function int infix_cal(const string& input) 
that takes a string in the format "<operand> <operator> <operand>" where <operand> is an integer and <operator> 
is one of "+,-,*,/". There are just two spaces  in the input string: one to separate the first operand with the operator
 and one to separate the operator and the second operand. For example, infix_cal("10 + 2") must return 12.
int infix_cal(const string& input) {
    size_t pos = input.find(" ",0);
    string op1,op2,op;
    op1 = input.substr(0,pos);
    op = input.substr(pos + 1,1);
    op2 = input.substr(pos + 3);
    int val1 = stoi(op1);
    int val2 = stoi(op2);
    if (op.compare("+")==0)
        return val1+val2;
    else if (op.compare("-")==0)
        return val1 - val2;
    else if (op.compare("*")==0)
        return val1 * val2;
    else
        return val1 / val2;
}
    
   