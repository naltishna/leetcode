#include "150_evaluate_reverse_polish_notation.h"

#include <stack>

namespace _150 {

    /*
    * Tokens are iterated left to right. Numbers are pushed onto the stack.
    * When an operator is encountered, the top two values are popped, the operation is applied, and the result is pushed back.
    * The final answer remains at the top of the stack.
    * 
    * Time complexity:
    * O(n)
    * 
    * Space complexity:
    * O(n)
    */
    int Solution::evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> digits;

        for (const std::string& t : tokens) {
            if (t.size() == 1 && (std::string("+-*/").find(t) != std::string::npos)) {
                int rightVal = digits.top(); digits.pop();
                int leftVal = digits.top(); digits.pop();

                digits.push(calc(leftVal, rightVal, t));
            }
            else {
                digits.push(std::stoi(t));
            }
        }

        return digits.top();
    }

    int Solution::calc(int a, int b, const std::string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;

        return 0;
    }

}