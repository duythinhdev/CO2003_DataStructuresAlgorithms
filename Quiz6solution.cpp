Write function string many_infix_cal(const string& input) that takes
a string containing many infix expressions in the format "<operand> <operator> <operand>" 
separated by new lines where operand is an integer constant and operator is one of +, - , * or /.
For example, a valid input string is "10 + 2\n14 * 2\n102 - 10" where there is exactly one space before or after an operator. 
The function returns a string containing the results of the input expressions separated by a space. 
For example, the function must return the string "12 28 92" for the above example.
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
string many_infix_cal(const string& input) {
    size_t pos = 0,newpos;
    string res;
    while ((newpos = input.find("\n",pos)) != string::npos) {
        int t = infix_cal(input.substr(pos,newpos-pos));
        res.append(to_string(t) + " ");
        pos = newpos + 1;
    }
    res.append(to_string(infix_cal(input.substr(pos))));
    return res;
}