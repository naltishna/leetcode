#include "97_interleaving_string.h"

#include <vector>

namespace _97 {

    /*
    * 2D dynamic programming approach.
    *
    * dp[i][j] = true if s3[0..i+j-1] can be formed by interleaving s1[0..i-1] and s2[0..j-1].
    * Each cell checks whether the current character comes from s1 or s2.
    *
    * Time complexity:
    * O(m x n) - every cell visited once
    *
    * Space complexity:
    * O(m x n) - full dp table
    */
    bool Solution::isInterleave(std::string s1, std::string s2, std::string s3) {
        const int m = static_cast<int>(s1.size());
        const int n = static_cast<int>(s2.size());

        if (m + n != static_cast<int>(s3.size())) {
            return false;
        }

        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                // Skip the first cell since it's already true.
                if (i == 0 && j == 0) {
                    continue;
                }

                // Get the index of the current character in s3.
                const int k = i + j - 1;

                // Check if the current character in s1 can be used to form the interleaving string.
                if (i > 0 && dp[i - 1][j] && s1[i - 1] == s3[k]) {
                    dp[i][j] = true;
                }

                // Check if the current character in s2 can be used to form the interleaving string.
                if (j > 0 && dp[i][j - 1] && s2[j - 1] == s3[k]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[m][n];
    }

}
