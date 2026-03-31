#include "20_valid_parentheses.h"

#include <stack>

namespace _20 {

    /*
    * Use the stack approach.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(N)
    */
    bool Solution::isValid(std::string s) {
        std::stack<char> st;

        for (auto ch : s) {
            if (ch == '(') {
                st.push(')');
            }
            else if (ch == '{') {
                st.push('}');
            }
            else if (ch == '[') {
                st.push(']');
            }
            else {
                if (st.empty() || ch != st.top()) return false;
                st.pop();
            }
        }

        return st.empty();
    }

}