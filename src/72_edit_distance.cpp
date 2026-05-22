#include "72_edit_distance.h"

#include <algorithm>
#include <vector>

namespace _72 {

    /*
    * 2D dynamic programming approach.
    *
    * This code implements the Wagner-Fischer algorithm using Dynamic Programming (DP) to solve the Levenshtein edit distance problem.
    * dp[i][j] stores the minimum edit distance between the prefix word1[0...i-1] and word2[0...j-1].
    *
    * Initialized in the first row and column. Converting an empty string to a string of length k requires k insertions or deletions.
    *
    * For each cell, if characters match, cost carries over from dp[i-1][j-1].
    * If they mismatch, the code takes the minimum of three operations plus a cost of 1:
    * - dp[i-1][j]: Deletion
    * - dp[i][j-1]: Insertion
    * - dp[i-1][j-1]: Replace
    *
    * Time complexity:
    * O(m x n) - every cell visited once
    *
    * Space complexity:
    * O(m x n) - full dp table
    */
    int Solution::minDistance(std::string word1, std::string word2) {
        const int m = static_cast<int>(word1.size());
        const int n = static_cast<int>(word2.size());

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

        // First row: j insertions to turn an empty string into word2[0..j-1] (word1 prefix length 0).
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }

        // First column: i deletions to turn word1[0..i-1] into an empty string (word2 prefix length 0).
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }

        // Fill the rest of the table with the minimum number of operations to turn word1[0..i-1] into word2[0..j-1].
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // If the current characters match, no operation is needed.
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                }
            }
        }

        return dp[m][n];
    }

}
