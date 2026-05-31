#include "212_word_search_II.h"
#include "class_version.h"

#include <functional>
#include <utility>
#include <vector>

namespace _212 {

    static constexpr std::pair<int, int> DIRECTIONS[] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    template<class V>
    void Solution<V>::buildTrie(std::vector<std::string>& words) {
        root = std::make_unique<TrieNode>();

        for (std::string& word : words) {
            TrieNode* node = root.get();

            for (char ch : word) {
                const int index = ch - 'a';
                if (!node->children[index]) {
                    node->children[index] = std::make_unique<TrieNode>();
                }

                node = node->children[index].get();
            }

            node->word = &word;
        }
    }

    /*
    * Approach: Trie + recursive DFS backtracking on the board.
    *
    * All target words are inserted into a Trie to enable fast prefix matching.
    * The algorithm starts a Depth-First Search (DFS) from every cell on the board.
    * DFS stops early if the current path of characters does not match any prefix in the Trie.
    * Cells are temporarily changed to # during DFS to avoid reusing the same letter in a single word path.
    * Once a word is found, its pointer in the Trie is set to nullptr to prevent adding duplicate words to the result.
    *
    * Time complexity:
    * O(m * n * 4^L), where m * n is the board size and L is the maximum length of a word.
    * In the worst case, the DFS explores up to 4 directions for each character up to length L.
    *
    * Space complexity:
    * O(W * L), where W is the number of words and L is the maximum word length.
    * This space is required to store the Trie structure in memory. The DFS recursion stack takes O(L) space.
    */
    template<>
    std::vector<std::string> Solution<ver1>::findWords(std::vector<std::vector<char>>& board,
        std::vector<std::string>& words) {
        std::vector<std::string> result;
        if (board.empty() || board[0].empty()) {
            return result;
        }

        buildTrie(words);

        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board[0].size());

        std::function<void(int, int, TrieNode*)> dfs = [&](int row, int col, TrieNode* node) {
            if (node->word != nullptr) {
                result.push_back(*node->word);
                node->word = nullptr;
            }

            // check if the cell is out of bounds
            if (row < 0 || row >= rows || col < 0 || col >= cols) {
                return;
            }

            const char saved = board[row][col];
            if (saved == '#') {
                return;
            }

            TrieNode* next = node->children[saved - 'a'].get();
            if (!next) {
                return;
            }

            board[row][col] = '#';

            // explore all neighbors
            for (const auto& [dRow, dCol] : DIRECTIONS) {
                dfs(row + dRow, col + dCol, next);
            }

            board[row][col] = saved;
            };

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (root->children[board[row][col] - 'a']) {
                    dfs(row, col, root.get());
                }
            }
        }

        return result;
    }

    /*
    * Approach: Trie + iterative DFS with explicit stack.
    *
    * Simulates recursive backtracking using stack frames with next-direction state.
    *
    * Time complexity:
    * O(m * n * 4^L + sum of word lengths)
    *
    * Space complexity:
    * O(total characters in words + stack depth)
    */
    template<>
    std::vector<std::string> Solution<ver2>::findWords(std::vector<std::vector<char>>& board,
        std::vector<std::string>& words) {
        std::vector<std::string> result;
        if (board.empty() || board[0].empty()) {
            return result;
        }

        buildTrie(words);

        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board[0].size());

        struct DfsFrame {
            int row;
            int col;
            TrieNode* node;
            char savedChar;
            bool isLeave;
        };

        std::vector<DfsFrame> stack;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                // initialize DFS for the current cell of the board
                stack.push_back({ row, col, root.get(), board[row][col], false });

                while (!stack.empty()) {
                    DfsFrame curr = stack.back();
                    stack.pop_back();

                    // if this is the backtracking stage, restore the cell
                    if (curr.isLeave) {
                        board[curr.row][curr.col] = curr.savedChar;
                        continue;
                    }

                    // check if the cell is out of bounds
                    if (curr.row < 0 || curr.row >= rows || curr.col < 0 || curr.col >= cols) {
                        continue;
                    }

                    char ch = board[curr.row][curr.col];
                    // if the cell is visited, skip it
                    if (ch == '#') {
                        continue;
                    }

                    // check if the cell is a valid trie node
                    TrieNode* nextNode = curr.node->children[ch - 'a'].get();
                    // if the cell is not a valid trie node, skip it
                    if (!nextNode) {
                        continue;
                    }

                    // found a word, save it
                    if (nextNode->word != nullptr) {
                        result.push_back(*nextNode->word);
                        nextNode->word = nullptr;
                    }

                    // 1. mark the cell as occupied
                    board[curr.row][curr.col] = '#';

                    // 2. push the command to restore the cell to the stack
                    stack.push_back({ curr.row, curr.col, nullptr, ch, true });

                    // 3. push all neighbors to the stack for exploration
                    for (const auto& dir : DIRECTIONS) {
                        int nextR = curr.row + dir.first;
                        int nextC = curr.col + dir.second;
                        stack.push_back({ nextR, nextC, nextNode, '\0', false });
                    }
                }
            }
        }

        return result;
    }

    template class Solution<ver1>;
    template class Solution<ver2>;

}
