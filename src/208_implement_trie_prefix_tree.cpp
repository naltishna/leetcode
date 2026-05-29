#include "208_implement_trie_prefix_tree.h"

namespace _208 {

    /*
    * Approach: Array-based trie.
    *
    * Each node stores 26 child pointers (one per lowercase letter) and a flag marking
    * the end of an inserted word. Insert/search/startsWith all walk the tree character by character.
    *
    * Time complexity:
    * O(m) per operation, where m is the length of the word or prefix
    *
    * Space complexity:
    * O(n * m), where n is the number of inserted words and m is the average word length
    */
    Trie::Trie() : root(std::make_unique<Node>()) {}

    void Trie::insert(const std::string& word) {
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

    bool Trie::search(const std::string& word) const {
        Node* node = root.get();

        for (char ch : word) {
            const int index = ch - 'a';
            if (!node->children[index]) {
                return false;
            }

            node = node->children[index].get();
        }

        return node->isEnd;
    }

    bool Trie::startsWith(const std::string& prefix) const {
        Node* node = root.get();

        for (char ch : prefix) {
            const int index = ch - 'a';
            if (!node->children[index]) {
                return false;
            }

            node = node->children[index].get();
        }

        return true;
    }

}
