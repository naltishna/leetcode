#include "139_word_break.h"
#include "class_version.h"

#include <algorithm>
#include <unordered_set>
#include <vector>

namespace _139 {

    namespace {

        bool search(const std::string& str, const std::unordered_set<std::string>& dict) {
            const int len = static_cast<int>(str.size());
            for (int i = 1; i <= len; ++i) {
                if (dict.contains(str.substr(0, i)) && (i == len || search(str.substr(i), dict))) {
                    return true;
                }
            }

            return false;
        }

    } // namespace

    /*
    * Brute-force recursion over all prefix splits.
    *
    * Time complexity:
    * O(2^n) worst case
    *
    * Space complexity:
    * O(n)
    */
    bool Solution<ver1>::wordBreak(std::string s, std::vector<std::string>& wordDict) {
        const std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());

        return search(s, dict);
    }

    /*
    * Bottom-up dynamic programming over start positions.
    *
    * For each position i, check all substrings ending at i (starting from i - maxWordLen) - if dp[j] is true
    * and s[j..i-1] is in the dict, then dp[i] = true.
    * 
    * Time complexity:
    * O(n * m * k) - n positions × m = maxWordLen × k = substr
    * 
    * Space complexity:
    * O(n + W) - dp vector + dict set
    */
    bool Solution<ver2>::wordBreak(std::string s, std::vector<std::string>& wordDict) {
        const std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());

        int maxWordLen = 0;
        for (const std::string& word : wordDict) {
            // Only the last word ending at i can start at i - maxWordLen.
            maxWordLen = std::max(maxWordLen, static_cast<int>(word.size()));
        }

        const int n = static_cast<int>(s.size());
        std::vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            const int start = std::max(0, i - maxWordLen);
            for (int j = start; j < i; ++j) {
                if (dp[j] && dict.contains(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

}
