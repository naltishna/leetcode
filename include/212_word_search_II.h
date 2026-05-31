/*
https://leetcode.com/problems/word-search-ii/description/

212. Word Search II

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells
are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 12
1 <= words.length <= 3 * 10^4
1 <= words[i].length <= 10
words[i] consists of only lowercase English letters.
board[i][j] is a lowercase English letter.
*/

#pragma once

#include <array>
#include <memory>
#include <string>
#include <vector>

namespace _212 {

    template <class V>
    class Solution {
        struct TrieNode {
            // 26 children for each small letter of the alphabet
            std::array<std::unique_ptr<TrieNode>, 26> children{};
            // pointer to the word that ends at this node
            std::string* word = nullptr;
        };

        std::unique_ptr<TrieNode> root;

        void buildTrie(std::vector<std::string>& words);

    public:
        std::vector<std::string> findWords(std::vector<std::vector<char>>& board,
                                           std::vector<std::string>& words);
    };

}
