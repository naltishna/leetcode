#include "290_word_pattern.h"
#include "class_version.h"

#include <unordered_map>
#include <sstream>
#include <vector>

namespace _290 {

    /*
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n), where n is the length of the string s (or the number of words).
    */
    template<>
    bool Solution<ver1>::wordPattern(std::string pattern, std::string s) {
        std::vector<std::string> words;
        std::stringstream ss(s);
        std::string word;

        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.length() != words.size()) return false;

        std::unordered_map<char, std::string> charToWord;
        std::unordered_map<std::string, char> wordToChar;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            std::string w = words[i];

            if (charToWord.count(c) && charToWord[c] != w) return false;
            if (wordToChar.count(w) && wordToChar[w] != c) return false;

            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }

    /*
    * Two hash maps to enforce a strict one-to-one correspondence between pattern characters and words.
    * 
    * charToWord: char -> string — ensures each pattern letter always maps to the same word
    * wordToChar: string -> char — ensures each word always maps to the same letter (prevents a->dog, b->dog)
    * 
    * Streams words via stringstream, checks both directions on each step, rejects mismatches immediately.
    * Edge cases handled explicitly: more words than letters, more letters than words.
    * 
    * Time complexity:
    * O(n) - single pass over words
    *
    * Space complexity:
    * O(k), where k is the number of unique words/letters (in the worst case also O(n)).
    */
    template<>
    bool Solution<ver2>::wordPattern(std::string pattern, std::string s) {
        std::stringstream ss(s);
        std::unordered_map<char, std::string> charToWord;
        std::unordered_map<std::string, char> wordToChar;

        std::string word;
        size_t i = 0;
        while (ss >> word) {
            if (i >= pattern.size()) {
                return false; // More words than pattern letters.
            }
            const char c = pattern[i];

            const auto cIt = charToWord.find(c);
            if (cIt != charToWord.end() && cIt->second != word) {
                return false;
            }
            const auto wIt = wordToChar.find(word);
            if (wIt != wordToChar.end() && wIt->second != c) {
                return false;
            }

            charToWord[c] = word;
            wordToChar[word] = c;
            ++i;
        }

        return i == pattern.size(); // Fail when pattern has extra letters.
    }

}