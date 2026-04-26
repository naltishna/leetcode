#include "3_longest_substring_without_repeating_characters.h"
#include "class_version.h"

#include <algorithm>
#include <array>

namespace _3 {

    /*
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver1>::lengthOfLongestSubstring(std::string s) {
        int n = static_cast<int>(s.size());
        if (n == 0) {
            return 0;
        }

        std::array<int, 256> last;
        last.fill(-1);
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            const auto c = static_cast<unsigned char>(s[right]);
            if (last[c] >= left) {
                left = last[c] + 1;
            }

            last[c] = right;
            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    /*
    * Expand window with right, shrink with left when duplicate found, tracking max window size with unique chars only.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver2>::lengthOfLongestSubstring(std::string s) {
        int n = static_cast<int>(s.size());
        if (n == 0) {
            return 0;
        }

        int maxLen = 0;
        int left = 0;
        std::array<int, 256> freq{};

        for (int right = 0; right < n; ++right) {
            unsigned char rightChar = s[right];
            freq[rightChar]++;

            // If the symbol is already in the window (duplicate), narrow the window on the left.
            while (freq[rightChar] > 1) {
                unsigned char leftChar = s[left];
                freq[leftChar]--;
                left++;
            }

            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }

}
