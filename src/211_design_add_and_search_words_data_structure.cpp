#include "211_design_add_and_search_words_data_structure.h"
#include "class_version.h"

#include <functional>
#include <vector>
#include <queue>

namespace _211 {

    template<class V>
    WordDictionary<V>::WordDictionary() : root(std::make_unique<Node>()) {}

    template<class V>
    void WordDictionary<V>::addWord(const std::string& word) {
        Node* node = root.get();

        for (char ch : word) {
            const int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = std::make_unique<Node>();
            }

            node = node->children[index].get();
        }

        node->isEnd = true;
    }

    /*
    * Approach: Trie + recursive DFS for wildcard search.
    *
    * Words are stored in a trie. Exact characters follow a single child edge; '.'
    * tries all existing children recursively.
    *
    * Time complexity:
    * O(m) for addWord, O(26^d * m) worst case for search with d dots
    *
    * Space complexity:
    * O(n * m), where n is the number of words and m is the average word length
    */
    template<>
    bool WordDictionary<ver1>::search(const std::string& word) const {
        std::function<bool(int, Node*)> searchWord = [&](int index, Node* node) -> bool {
            if (index == static_cast<int>(word.size())) {
                return node->isEnd;
            }

            // if the character is a dot, try all existing children
            if (word[index] == '.') {
                for (const auto& child : node->children) {
                    if (child && searchWord(index + 1, child.get())) {
                        return true;
                    }
                }

                return false;
            }

            // if the character is a regular character, check only one branch
            const int charIndex = word[index] - 'a';
            if (!node->children[charIndex]) {
                return false;
            }

            // check the next character
            return searchWord(index + 1, node->children[charIndex].get());
        };

        return searchWord(0, root.get());
    }

    /*
    * Approach: BFS (Breadth-First Search) with a queue.
    *
    * Each queue element stores the current trie node and index in the search word.
    * For '.', all existing children are added to the queue.
    *
    * Time complexity:
    * O(m) for addWord, O(26^d * m) worst case for search with d dots, d is the number of dots
    *
    * Space complexity:
    * O(n * m) - trie size; O(m) queue depth for search, n is the number of words, m is the average word length
    */
    template<>
    bool WordDictionary<ver2>::search(const std::string& word) const {
        std::queue<std::pair<const Node*, int>> q;
        q.push({root.get(), 0});
    
        const int wordSize = static_cast<int>(word.size());
    
        while (!q.empty()) {
            auto [node, index] = q.front();
            q.pop();
    
            // if we reached the end of the word, check the end flag
            if (index == wordSize) {
                if (node->isEnd) {
                    return true;
                }

                // continue to check other branches in the queue
                continue; 
            }
    
            char ch = word[index];
    
            if (ch == '.') {
                // if the dot, add all existing children to the queue
                for (const auto& child : node->children) {
                    if (child) {
                        q.push({child.get(), index + 1});
                    }
                }
            } else {
                // if the regular character, check only one branch
                const int charIndex = ch - 'a';
                if (node->children[charIndex]) {
                    q.push({node->children[charIndex].get(), index + 1});
                }
            }
        }
    
        return false;
    }

    template class WordDictionary<ver1>;
    template class WordDictionary<ver2>;

}
