/*
https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

211. Design Add and Search Words Data Structure

Design a data structure that supports adding new words and finding if a string matches any
previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure.
bool search(word) Returns true if there is any string in the data structure that matches word
or false otherwise. word may contain dots '.' where dots can be matched with any letter.

Example:
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Constraints:
1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 10^4 calls will be made to addWord and search.
*/

#pragma once

#include <array>
#include <memory>
#include <string>

namespace _211 {

    template <class V>
    class WordDictionary {
        struct Node {
            std::array<std::unique_ptr<Node>, 26> children{};
            bool isEnd = false;
        };

        std::unique_ptr<Node> root;

    public:
        WordDictionary();

        void addWord(const std::string& word);

        bool search(const std::string& word) const;
    };

}
