//Write function int infix_cal(const string& input) that takes a string in the format "<operand> <operator> <operand>" where <operand> is an integer and <operator> is one of "+,-,*,/".There are just two spaces  in the input string : one to separate the first operand with the
//operator and one to separate the operator and the second operand.For example, infix_cal("10 + 2") must return 12.
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int perform_operation(int op1, int op2, char op) {
    switch (op) {
    case '+': return op1 + op2;
    case '-': return op1 - op2;
    case '*': return op1 * op2;
    case '/': return op1 / op2;
    default: return 0;
    }
}

int infix_cal(const string & input) {
    stack<int> operands;
    stack<char> operators;

    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i])) {
            int operand = 0;
            while (i < input.length() && isdigit(input[i])) {
                operand = operand * 10 + (input[i] - '0');
                i++;
            }
            operands.push(operand);
            i--;
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
                int op2 = operands.top();
                operands.pop();
                int op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                operands.push(perform_operation(op1, op2, op));
            }
            operators.push(input[i]);
        }
    }

    while (!operators.empty()) {
        int op2 = operands.top();
        operands.pop();
        int op1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        operands.push(perform_operation(op1, op2, op));
    }

    return operands.top();
}

int main() {
    cout << infix_cal("10 + 2") << endl;
    return 0;
}
