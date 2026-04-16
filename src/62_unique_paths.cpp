#include "62_unique_paths.h"

#include <vector>

namespace _62 {

    /*
     * Dynamic programming approach.
     * A 2D DP table is filled where each cell dp[i][j] represents the number of unique paths to reach that cell.
     * The first row and column are initialized to 1 (only one way to reach any edge cell),
     * then each remaining cell is computed as the sum of paths from the cell above and the cell to the left — since you can only move right or down.
     *
     * Time complexity:
     * O(m x n)
     *
     * Space complexity:
     * O(m x n)
     */
    int Solution::uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

}