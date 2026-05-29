#include "22_generate_parentheses.h"
#include "class_version.h"

#include <functional>
#include <string>
#include <vector>

namespace _22 {

    /*
    * Approach: Backtracking.
    *
    * Builds strings character by character. Adds '(' while open < n,
    * adds ')' while close < open.
    *
    * Time complexity:
    * O(4^n / sqrt(n)) - Catalan number of valid strings, each length 2n
    *
    * Space complexity:
    * O(n) - recursion depth and current string (excluding output)
    */
    template<>
    std::vector<std::string> Solution<ver1>::generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current;

        std::function<void(int, int)> backtrack = [&](int open, int close) {
            if (static_cast<int>(current.size()) == 2 * n) {
                result.push_back(current);
                return;
            }

            if (open < n) {
                current.push_back('(');
                backtrack(open + 1, close);
                current.pop_back();
            }

            if (close < open) {
                current.push_back(')');
                backtrack(open, close + 1);
                current.pop_back();
            }
            };

        backtrack(0, 0);

        return result;
    }

    /*
    * Approach: Iterative backtracking with explicit stack.
    *
    * Use std::vector as a stack of {open, close, current} to simulate recursion.
    * Pushes the ')' branch before '(' so '(' is processed first. Complete string
    * at length 2n is added to result.
    *
    * Time complexity:
    * O(4^n / sqrt(n))
    *
    * Space complexity:
    * O(n) - stack depth and current string (excluding output)
    */
    template<>
    std::vector<std::string> Solution<ver2>::generateParenthesis(int n) {
        std::vector<std::string> result;

        struct Frame {
            int open;
            int close;
            std::string current;
        };

        std::vector<Frame> stack;
        stack.push_back({ 0, 0, "" });

        while (!stack.empty()) {
            Frame frame = std::move(stack.back());
            stack.pop_back();

            if (static_cast<int>(frame.current.size()) == 2 * n) {
                result.push_back(frame.current);
                continue;
            }

            if (frame.close < frame.open) {
                std::string next = frame.current;
                next.push_back(')');
                stack.push_back({ frame.open, frame.close + 1, std::move(next) });
            }

            if (frame.open < n) {
                std::string next = frame.current;
                next.push_back('(');
                stack.push_back({ frame.open + 1, frame.close, std::move(next) });
            }
        }

        return result;
    }

}
