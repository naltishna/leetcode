#include "30_substring_with_concatenation_of_all_words.h"
#include "class_version.h"

#include <algorithm>
#include <unordered_map>

namespace _30 {

    /*
    * Time complexity:
    * O(k! * n * k * m), where k = words.size(), m = length of one word, n = s.size()
    *
    * Space complexity:
    * O(k! * k * m)
    */
    template<>
    std::vector<int> Solution<ver1>::findSubstring(std::string s, std::vector<std::string>& words) {
        std::sort(words.begin(), words.end());

        std::vector<std::string> wordsComb;
        do {
            std::string com = "";
            for (const std::string& w : words) {
                com += w;
            }

            wordsComb.push_back(com);

        } while (std::next_permutation(words.begin(), words.end()));

        std::vector<int> output;
        for (auto& w : wordsComb) {
            size_t pos = 0;
            while ((pos = s.find(w, pos)) != std::string::npos) {
                output.push_back(static_cast<int>(pos));
                pos++;
            }
        }

        return output;
    }

    /*
    * Time complexity:
    * O((n - k*m + 1) * k * m), where k = words.size(), m = length of one word, n = s.size()
    *
    * Space complexity:
    * O(k)
    */
    template<>
    std::vector<int> Solution<ver2>::findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> output;
        if (s.empty() || words.empty()) {
            return output;
        }

        int wordLen = words[0].length(); // All the strings of words are of the same length.
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.length() < totalLen) {
            return output;
        }

        std::unordered_map<std::string, int> wordFreq;
        for (const std::string& w : words) {
            wordFreq[w]++;
        }

        for (int i = 0; i <= static_cast<int>(s.length() - totalLen); ++i) { // A limitation of the window boundaries so as not to go beyond the end of the line.
            std::unordered_map<std::string, int> seen;
            int j = 0;

            for (; j < wordCount; ++j) {
                std::string part = s.substr(i + j * wordLen, wordLen);
                if (wordFreq.find(part) != wordFreq.end()) {
                    seen[part]++;
                    if (seen[part] > wordFreq[part]) {
                        break;
                    }
                }
                else {
                    break;
                }
            }

            if (j == wordCount) {
                output.push_back(i);
            }
        }

        return output;
    }

    /*
    * Run wordLen independent sliding windows (one per offset), each stepping by wordLen.
    * Track word frequencies in window; shrink from left on excess or invalid word.
    *
    * Time complexity:
    * O(n * m), where m = length of one word, n = s.size()
    *
    * Space complexity:
    * O(k), where k = words.size()
    */
    template<>
    std::vector<int> Solution<ver3>::findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> output;
        if (s.empty() || words.empty()) {
            return output;
        }

        int wordLen = static_cast<int>(words[0].length()); // All the strings of words are of the same length.
        int wordCount = static_cast<int>(words.size());
        int totalLen = wordLen * wordCount;
        int n = static_cast<int>(s.length());

        if (n < totalLen) {
            return output;
        }

        std::unordered_map<std::string, int> wordFreq;
        for (const std::string& w : words) {
            wordFreq[w]++;
        }

        for (int offset = 0; offset < wordLen; ++offset) {
            int left = offset;
            int matchedWords = 0;
            std::unordered_map<std::string, int> windowFreq;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                std::string word = s.substr(right, wordLen);
                if (wordFreq.find(word) == wordFreq.end()) {
                    windowFreq.clear();
                    matchedWords = 0;
                    left = right + wordLen;
                    continue;
                }

                windowFreq[word]++;
                matchedWords++;

                while (windowFreq[word] > wordFreq[word]) {
                    std::string leftWord = s.substr(left, wordLen);
                    windowFreq[leftWord]--;
                    left += wordLen;
                    matchedWords--;
                }

                if (matchedWords == wordCount) {
                    output.push_back(left);
                    std::string leftWord = s.substr(left, wordLen);
                    windowFreq[leftWord]--;
                    left += wordLen;
                    matchedWords--;
                }
            }
        }

        return output;
    }

}