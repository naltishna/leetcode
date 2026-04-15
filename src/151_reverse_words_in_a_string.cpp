#include "151_reverse_words_in_a_string.h"
#include "class_version.h"

#include <sstream>
#include <queue>

namespace _151 {

    /*
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(N)
    */
    template<>
    std::string Solution<v1>::reverseWords(std::string s) {
        std::deque<std::string> dq;
        std::string word;
        std::istringstream stream(s);

        while (stream >> word) {
            dq.push_front(word);
        }

        if (dq.empty()) return "";

        std::string result = dq.front();
        for (size_t i = 1; i < dq.size(); ++i) {
            result += " " + dq[i];
        }
        return result;
    }

    /*
    * Reverse the entire string, then reverse each word individually to restore word order.
    * Finally, remove extra spaces in-place using a two-pointer technique.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    template<>
    std::string Solution<v2>::reverseWords(std::string s) {
        // reverse the entire line
        reverse(s.begin(), s.end());

        // reverse each word back
        size_t start = 0;
        size_t n = s.size();
        for (size_t i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                std::reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        // remove extra white spaces
        size_t slow = 0;
        bool isWord = false;
        for (size_t i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                if (isWord) {
                    s[slow++] = ' ';
                }

                while (i < n && s[i] != ' ') {
                    s[slow++] = s[i++];
                }
                isWord = true;
            }
        }
        s.resize(slow);

        return s;
    }

}