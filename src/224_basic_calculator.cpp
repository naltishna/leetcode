#include "224_basic_calculator.h"

#include <stack>

namespace _224_basic_calculator {

    /*
    * The current approach does not parse "-2 + 1" case correctly.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(N)
    */
    int Solution::calculate(std::string s) {
        std::stack<int> digits;
        std::stack<char> ops;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;

            if (isdigit(s[i])) {
                int val = 0;
                while (i < n && isdigit(s[i])) {
                    val = (val * 10) + (s[i] - '0');
                    i++;
                }
                digits.push(val);
                i--;
            }
            else if (s[i] == '(') {
                ops.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    int rightVal = digits.top(); digits.pop();
                    int leftVal = digits.top(); digits.pop();
                    char op = ops.top(); ops.pop();

                    digits.push(applyCalc(leftVal, rightVal, op));
                }
                ops.pop(); // remove '('
            }
            else { // any operation
                while (!ops.empty() && priority(ops.top()) >= priority(s[i])) {
                    int rightVal = digits.top(); digits.pop();
                    int leftVal = digits.top(); digits.pop();
                    char op = ops.top(); ops.pop();

                    digits.push(applyCalc(leftVal, rightVal, op));
                }
                ops.push(s[i]);
            }
        }

        // applay remaining operations
        while (!ops.empty()) {
            int rightVal = digits.top(); digits.pop();
            int leftVal = digits.top(); digits.pop();
            char op = ops.top(); ops.pop();

            digits.push(applyCalc(leftVal, rightVal, op));
        }

        return digits.top();
    }

    int Solution::applyCalc(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }

        return 0;
    }

    int Solution::priority(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;

        return 0;
    }

}


namespace _224_unary_minus {

    /*
    * It scans the string from left to right, builds multi-digit numbers, and keeps track of the current sign and partial result.
    * When it sees '(', it saves the current context on the stack, and when it sees ')', it restores that saved context and combines it with the inner expression result.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(N)
    */
    int Solution::calculate(std::string s) {
        std::stack<int> st;
        int res = 0;
        int sign = 1;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;

            if (isdigit(s[i])) {
                long long val = 0;
                while (i < n && isdigit(s[i])) {
                    val = (val * 10) + (s[i] - '0');
                    i++;
                }

                res += val * sign;
                i--;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            else if (s[i] == '+') {
                sign = 1;
            }
            else if (s[i] == '(') {
                st.push(res);
                st.push(sign);

                res = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                int prevSign = st.top(); st.pop();
                int prevRes = st.top(); st.pop();

                res = prevRes + (res * prevSign);
            }
        }

        return res;
    }

}