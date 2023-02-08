#include <string>
#include <stack>

int infix_cal(const std::string& input) {
    std::stack<int> operands;
    std::stack<char> operators;
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (c >= '0' && c <= '9') {
            int operand = 0;
            while (i < input.length() && input[i] >= '0' && input[i] <= '9') {
                operand = operand * 10 + (input[i] - '0');
                i++;
            }
            operands.push(operand);
            i--;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
                int op2 = operands.top();
                operands.pop();
                int op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                if (op == '*') operands.push(op1 * op2);
                else operands.push(op1 / op2);
            }
            operators.push(c);
        }
    }
    while (!operators.empty()) {
        int op2 = operands.top();
        operands.pop();
        int op1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        if (op == '+') operands.push(op1 + op2);
        else operands.push(op1 - op2);
    }
    return operands.top();
}
This implementation uses two stacks: one for operands and another for operators.
It iterates through the input string, pushing operands onto the operand stack and operators onto the operator stack. 
Whenever the operator stack contains an operator with higher precedence (i.e., * or /), 
it evaluates the expression by popping the two most recent operands, performing the operation, and pushing the result back onto the operand stack.
Finally, it evaluates any remaining expressions in the operator stack by popping the two most recent operands, performing the operation,
and pushing the result back onto the operand stack. The final result will be the only item left on the operand stack.