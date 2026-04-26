#include "76_minimum_window_substring.h"

#include <array>
#include <limits>

namespace _76 {

    /*
    * Two-pointer sliding window with frequency arrays:
    * - Count character frequencies in t;
    * - Expand right pointer, tracking how many required chars are satisfied;
    * - Once all chars covered (required == 0) — shrink from left to minimize window;
    * - Track minimum valid window throughout.
    * 
    * Time complexity:
    * O(n + m), where n = s.size(), m = t.size() — each character visited at most twice (once by right, once by left)
    * 
    * Space complexity:
    * O(1) — fixed-size arrays of 128 chars
    */
    std::string Solution::minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }

        std::array<int, 128> tFreq{};
        for (unsigned char ch : t) {
            tFreq[ch]++;
        }

        int required = static_cast<int>(t.size());
        int minLen = std::numeric_limits<int>::max();
        int left = 0;
        int startPos = 0;

        std::array<int, 128> windowFreq{};

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char rightChar = static_cast<unsigned char>(s[right]);

            windowFreq[rightChar]++;

            if (windowFreq[rightChar] <= tFreq[rightChar]) {
                required--;
            }

            while (required == 0) {
                int windowLen = right - left + 1;

                if (windowLen < minLen) {
                    minLen = windowLen;
                    startPos = left;
                }

                unsigned char leftChar = static_cast<unsigned char>(s[left]);
                windowFreq[leftChar]--;

                if (windowFreq[leftChar] < tFreq[leftChar]) {
                    required++;
                }

                left++;
            }
        }

        return minLen == std::numeric_limits<int>::max() ? "" : s.substr(startPos, minLen);
    }

}