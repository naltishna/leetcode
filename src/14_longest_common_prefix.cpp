#include "14_longest_common_prefix.h"

namespace _14 {

    /*
    * Horizontal (symbol-by-symbol) approach.
    *
    * Time complexity:
    * O(N * M), where N is the number of rows in the array, M is the minimum length of the shortest row.
    *
    * Space complexity:
    * O(M)
    */
    std::string Solution::longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";

        std::string result;
        size_t minLen = strs[0].length();

        for (const auto& str : strs) {
            minLen = std::min(minLen, str.length());
        }

        for (size_t i = 0; i < minLen; ++i) {
            char ch = strs[0][i];
            for (size_t j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != ch) {
                    return result;
                }
            }

            result += ch;
        }

        return result;
    }

}