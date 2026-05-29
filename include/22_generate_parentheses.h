/*
https://leetcode.com/problems/generate-parentheses/description/

22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
*/

#pragma once

#include <string>
#include <vector>

namespace _22 {

    template <class V>
    class Solution {
    public:
        std::vector<std::string> generateParenthesis(int n);
    };

}
