#include "301_remove_invalid_parentheses.h"
#include "class_version.h"

#include <unordered_set>
#include <queue>

namespace _301 {

    bool isValid(const std::string& s) {
        int balance = 0;

        for (char ch : s) {
            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {
                balance--;
            }

            if (balance < 0) return false;
        }
        
        return balance == 0;
    }

    /*
    * BFS (Breadth-First Search) approach.
    * 
    * Time complexity:
    * O(N∗2^N)
    * 
    * Space complexity:
    * O(2^N)
    */
    template<>
    std::vector<std::string> Solution<ver1>::removeInvalidParentheses(std::string s) {
        std::vector<std::string> res;
        std::unordered_set<std::string> visited;
        std::queue <std::string> q;

        bool found = false;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            std::string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                res.push_back(curr);
                found = true;
            }

            if (found) {
                continue;
            }

            for (int i = 0; i < curr.size(); ++i) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                std::string next = curr.substr(0, i) + curr.substr(i + 1);

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return res;
    }

    
    void dfs(const std::string& s, int index, int left, int right, int balance, 
        std::string path, std::unordered_set<std::string>& res) {
        if (index == s.size()) {
            if (left == 0 && right == 0 && balance == 0) {
                res.insert(path);
            }
            return;
        }

        if (balance < 0) return;

        char ch = s[index];

        if (ch == '(' && left > 0) {
            dfs(s, index + 1, left - 1, right, balance, path, res);
        }
        else if (ch == ')' && right > 0) {
            dfs(s, index + 1, left, right - 1, balance, path, res);
        }

        if (ch == '(') {
            dfs(s, index + 1, left, right, balance + 1, path + ch, res);
        }
        else if (ch == ')') {
            dfs(s, index + 1, left, right, balance - 1, path + ch, res);
        }
        else {
            dfs(s, index + 1, left, right, balance, path + ch, res);
        }
    }

    /*
    * DFS (Depth-First Search) recursion approach.
    *
    * Time complexity:
    * O(N∗2^N)
    *
    * Space complexity:
    * O(2^N)
    */
    template<>
    std::vector<std::string> Solution<ver2>::removeInvalidParentheses(std::string s) {
        int left_to_remove = 0;
        int right_to_remove = 0;

        for (char ch : s) {
            if (ch == '(') {
                left_to_remove++;
            }
            else if (ch == ')') {
                if (left_to_remove > 0) left_to_remove--;
                else right_to_remove++;
            }
        }

        std::unordered_set<std::string> res;
        dfs(s, 0, left_to_remove, right_to_remove, 0, "", res);
        return std::vector<std::string>(res.begin(), res.end());
    }

}