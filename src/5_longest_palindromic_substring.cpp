#include "5_longest_palindromic_substring.h"
#include "class_version.h"

namespace _5 {

    /*
    * Brute force approach.
    *
    * Checks every possible substring s[i..j] for palindrome validity using a two-pointer isPalindrome lambda.
    * Updates best result when a longer palindrome is found.
    *
    * Time complexity:
    * O(n³) - O(n²) substrings, each palindrome check costs O(n)
    *
    * Space complexity:
    * O(1) - no extra data structures, lambda captures by reference
    */
    template <>
    std::string Solution<ver1>::longestPalindrome(std::string s) {
        const int n = static_cast<int>(s.size());
        if (n == 0) {
            return "";
        }

        auto isPalindrome = [](const std::string& str, int left, int right) {
            while (left < right) {
                if (str[left++] != str[right--]) {
                    return false;
                }
            }

            return true;
            };

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isPalindrome(s, i, j) && j - i + 1 > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(static_cast<size_t>(start), static_cast<size_t>(maxLen));
    }

    /*
    * Expand around center for every index (odd and even palindromes).
    *
    * Time complexity:
    * O(n^2)
    *
    * Space complexity:
    * O(1)
    */
    template <>
    std::string Solution<ver2>::longestPalindrome(std::string s) {
        auto expandAroundCenter = [](const std::string& str, int left, int right, int& start, int& maxLen) {
            while (left >= 0 && right < static_cast<int>(str.size()) && str[left] == str[right]) {
                --left;
                ++right;
            }

            const int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
            };

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            expandAroundCenter(s, i, i, start, maxLen);
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(static_cast<size_t>(start), static_cast<size_t>(maxLen));
    }

}
