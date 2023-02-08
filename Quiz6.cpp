Write function string many_infix_cal(const string& input) that takes a string containing many 
infix expressions in the format "<operand> <operator> <operand>" separated by new lines where
operand is an integer constant and operator is one of +, - , * or /. For example, 
a valid input string is "10 + 2\n14 * 2\n102 - 10" where there is exactly one space before or after an operator. 
The function returns a string containing the results of the input expressions separated by a space. 
For example, the function must return the string "12 28 92" for the above example.

string many_infix_cal(const string& input) {
    istringstream iss(input);
    string line, result;
    while (getline(iss, line)) {
        result += to_string(infix_cal(line)) + " ";
    }
    return result.substr(0, result.length() - 1);
}