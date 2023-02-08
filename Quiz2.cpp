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
#include <string>
#include <stack>
#include <array>
using namespace std;
int infix_cal(const std::string& input) {
    std::stack<int> operands;
    std::stack<char> operators;
    std::string curr_operand;

    std::array<action, 4> actions = {
        {{"+", myadd}, {"-", mymin}, {"*", mymul}, {"/", mydiv}}
    };

    for (char c : input) {
        if (c == ' ') {
            // finished reading an operand, push it onto the stack
            operands.push(std::stoi(curr_operand));
            curr_operand.clear();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // encountered an operator, perform any pending operations
            while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
                int op2 = operands.top();
                operands.pop();
                int op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                for (const auto& act : actions) {
                    if (op == act.op[0]) {
                        operands.push(act.func(op1, op2));
                        break;
                    }
                }
            }

            operators.push(c);
        } else {
            // reading an operand
            curr_operand += c;
        }
    }

    // push the last operand onto the stack
    operands.push(std::stoi(curr_operand));

    // perform any pending operations
    while (!operators.empty()) {
        int op2 = operands.top();
        operands.pop();
        int op1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();

        for (const auto& act : actions) {
            if (op == act.op[0]) {
                operands.push(act.func(op1, op2));
                break;
            }
        }
    }

    // the result is on the top of the stack
    return operands.top();
}