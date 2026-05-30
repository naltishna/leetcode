#include "79_word_search.h"
#include "class_version.h"

#include <array>
#include <functional>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace _79 {

    static constexpr std::pair<int, int> DIRECTIONS[] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    /*
    * Approach: DFS (Depth-First Search) backtracking.
    *
    * Tries to match word starting from each cell. Marks visited cells temporarily
    * and restores them on backtrack.
    *
    * Time complexity:
    * O(m * n * 4^L), where m and n are board dimensions and L is word length
    *
    * Space complexity:
    * O(L) - recursion depth
    */
    template<>
    bool Solution<ver1>::exist(std::vector<std::vector<char>>& board, const std::string& word) {
        if (word.empty()) {
            return true;
        }

        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board[0].size());

        std::function<bool(int, int, int)> dfs = [&](int row, int col, int index) -> bool {
            if (index == static_cast<int>(word.size())) {
                return true;
            }

            if (row < 0 || row >= rows || col < 0 || col >= cols) {
                return false;
            }

            if (board[row][col] != word[index]) {
                return false;
            }

            const char saved = board[row][col];
            board[row][col] = '#';

            for (const auto& [dRow, dCol] : DIRECTIONS) {
                if (dfs(row + dRow, col + dCol, index + 1)) {
                    board[row][col] = saved;

                    return true;
                }
            }

            // restore the cell
            board[row][col] = saved;

            return false;
            };

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (dfs(row, col, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    /*
    * Approach: Iterative DFS with explicit stack.
    *
    * Each stack frame stores current cell, matched index, next direction to try,
    * and the saved character for backtracking.
    *
    * Time complexity:
    * O(m * n * 4^L)
    *
    * Space complexity:
    * O(L) - stack depth
    */
    template<>
    bool Solution<ver2>::exist(std::vector<std::vector<char>>& board, const std::string& word) {
        if (word.empty()) {
            return true;
        }

        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board[0].size());

        struct Frame {
            int row;
            int col;
            int index;
            int nextDir;
            char saved;
        };

        auto restoreStack = [&](const std::vector<Frame>& stack) {
            for (const Frame& frame : stack) {
                board[frame.row][frame.col] = frame.saved;
            }
            };

        auto searchFrom = [&](int startRow, int startCol) -> bool {
            if (board[startRow][startCol] != word[0]) {
                return false;
            }

            std::vector<Frame> stack;
            const char saved = board[startRow][startCol];
            board[startRow][startCol] = '#';
            stack.push_back({ startRow, startCol, 0, 0, saved });

            while (!stack.empty()) {
                Frame& frame = stack.back();

                if (frame.index == static_cast<int>(word.size()) - 1) {
                    restoreStack(stack);
                    return true;
                }

                if (frame.nextDir == 4) {
                    board[frame.row][frame.col] = frame.saved;
                    stack.pop_back();
                    continue;
                }

                const int direction = frame.nextDir++;
                const int nextRow = frame.row + DIRECTIONS[direction].first;
                const int nextCol = frame.col + DIRECTIONS[direction].second;
                const int nextIndex = frame.index + 1;

                if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) {
                    continue;
                }

                if (board[nextRow][nextCol] != word[nextIndex]) {
                    continue;
                }

                const char nextSaved = board[nextRow][nextCol];
                board[nextRow][nextCol] = '#';
                stack.push_back({ nextRow, nextCol, nextIndex, 0, nextSaved });
            }

            return false;
            };

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (searchFrom(row, col)) {
                    return true;
                }
            }
        }

        return false;
    }

    /*
    * Approach: Trie-guided DFS (Word Search II style, single word).
    *
    * Inserts the target word into a trie, then walks the board while following trie edges.
    * Dead-end branches are pruned when no trie child exists for the next character.
    *
    * Time complexity:
    * O(m * n * 4^L)
    *
    * Space complexity:
    * O(L) - trie size and recursion depth
    */
    template<>
    bool Solution<ver3>::exist(std::vector<std::vector<char>>& board, const std::string& word) {
        if (word.empty()) {
            return true;
        }

        struct TrieNode {
            std::array<std::unique_ptr<TrieNode>, 52> children{};
            bool isEnd = false;

            static int charIndex(char ch) {
                if (ch >= 'A' && ch <= 'Z') {
                    return ch - 'A';
                }

                if (ch >= 'a' && ch <= 'z') {
                    return ch - 'a' + 26;
                }

                return -1;
            }
        };

        TrieNode root;

        TrieNode* node = &root;
        for (char ch : word) {
            const int index = TrieNode::charIndex(ch);
            if (!node->children[index]) {
                node->children[index] = std::make_unique<TrieNode>();
            }

            // move to the next node
            node = node->children[index].get();
        }

        // mark the end of the word
        node->isEnd = true;

        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board[0].size());

        std::function<bool(int, int, TrieNode*)> dfs = [&](int row, int col, TrieNode* node) -> bool {
            const int index = TrieNode::charIndex(board[row][col]);
            TrieNode* next = node->children[index].get();

            if (!next) {
                return false;
            }

            if (next->isEnd) {
                return true;
            }

            const char saved = board[row][col];
            board[row][col] = '#';

            for (const auto& [dRow, dCol] : DIRECTIONS) {
                const int nextRow = row + dRow;
                const int nextCol = col + dCol;

                if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) {
                    continue;
                }

                if (board[nextRow][nextCol] == '#') {
                    continue;
                }

                if (dfs(nextRow, nextCol, next)) {
                    board[row][col] = saved;
                    return true;
                }
            }

            board[row][col] = saved;

            return false;
            };

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                const int index = TrieNode::charIndex(board[row][col]);
                if (index < 0 || !root.children[index]) {
                    continue;
                }

                if (dfs(row, col, &root)) {
                    return true;
                }
            }
        }

        return false;
    }

    /*
    * Approach: DFS (Depth-First Search) with backtracking.
    *
    * Tries to match word starting from each cell. Marks visited cells temporarily
    * and restores them on backtrack.
    *
    * Time complexity:
    * O(m * n * 4^L) - m * n cells, 4 directions, L length of word
    *
    * Space complexity:
    * O(L) - recursion depth and board copy
    */
    template<>
    bool Solution<ver4>::exist(std::vector<std::vector<char>>& board, const std::string& word) {
        if (word.empty()) {
            return true;
        }

        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board[0].size());

        std::function<bool(int, int, int)> dfs = [&](int row, int col, int index) -> bool {
            if (index == static_cast<int>(word.size())) {
                return true;
            }

            if (row < 0 || row >= rows || col < 0 || col >= cols) {
                return false;
            }

            if (board[row][col] != word[index]) {
                return false;
            }

            // mark the cell as visited
            const char saved = board[row][col];
            board[row][col] = '#';

            bool found =
                dfs(row + 1, col, index + 1) || // Down
                dfs(row - 1, col, index + 1) || // Up
                dfs(row, col + 1, index + 1) || // Right
                dfs(row, col - 1, index + 1);   // Left

            // restore the cell
            board[row][col] = saved;

            return found;
        };

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (dfs(row, col, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
}
