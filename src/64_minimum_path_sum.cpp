#include "64_minimum_path_sum.h"

namespace _64 {

    /*
    * Dynamic programming approach.
    *
    * Each cell stores the minimum path sum to reach it.
    * Can only move right or down, so each cell takes grid[i][j] + min(top, left).
    * First row and column seeded independently as they have only one path.
    *
    * Time complexity:
    * O(m * n) - every cell visited once
    *
    * Space complexity:
    * O(m * n) - full dp table
    */
    int Solution::minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        const size_t rows = grid.size();
        const size_t cols = grid[0].size();
        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        dp[0][0] = grid[0][0];

        // fill first row
        for (int j = 1; j < cols; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // fill first column
        for (int i = 1; i < rows; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // fill rest
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                dp[i][j] = grid[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[rows - 1][cols - 1];
    }

}
