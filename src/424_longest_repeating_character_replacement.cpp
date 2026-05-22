#include "424_longest_repeating_character_replacement.h"
#include "class_version.h"


#include <array>

namespace _424 {

    /*
    * Using a Sliding window algorithm to maintain the longest valid substring where replacements do not exceed k.
    *
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver1>::characterReplacement(std::string s, int k) {
        std::array<int, 26> freq{};

        int left = 0;
        int maxCount = 0;
        int maxlenth = 0;

        for (int right = 0; right < s.length(); ++right) {
            freq[s.at(right) - 'A']++;

            maxCount = std::max(maxCount, freq[s.at(right) - 'A']);

            while (right - left + 1 > maxCount + k) {
                freq[s.at(left) - 'A']--;
                left++;
            }
            maxlenth = std::max(maxlenth, right - left + 1);
        }

        return maxlenth;
    }

    /*
    * The sliding window algorithm is used to find the longest substring with the same letter after performing the above operations.
    *
    * The window is expanded by moving the right pointer to the right and the left pointer to the right when the number of replacements exceeds k.
    * The window is shrunk by moving the left pointer to the right when the number of replacements exceeds k.
    * The window is expanded by moving the right pointer to the right when the number of replacements exceeds k.
    * The window is shrunk by moving the left pointer to the right when the number of replacements exceeds k.
    *
    *
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    template<>
    int Solution<ver2>::characterReplacement(std::string s, int k) {
        std::array<int, 26> freq{};
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); ++right) {
            freq[s[right] - 'A']++;

            // How much letters need to replace in the current window
            int windowSize = right - left + 1;
            int mostFrequent = *std::max_element(freq.begin(), freq.end());
            int charsToReplace = windowSize - mostFrequent;

            // If there are too many replacements, narrow the window on the left
            if (charsToReplace > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }

}