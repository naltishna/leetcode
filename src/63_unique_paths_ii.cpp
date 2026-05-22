#include "63_unique_paths_ii.h"

namespace _63 {

    /*
    * Dynamic programming approach.
    *
    * Each cell stores the number of unique paths to reach it. Obstacles (1) block the cell - set to 0.
    * First row/column seeded with 1 until an obstacle is hit (break),
    * since any cell after an obstacle in a single row/column is unreachable.
    *
    * Time complexity:
    * O(m * n) - every cell visited once
    *
    * Space complexity:
    * O(m * n) - full dp table
    */
    int Solution::uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        const int rows = static_cast<int>(obstacleGrid.size());
        const int cols = static_cast<int>(obstacleGrid[0].size());

        // If the start or end is an obstacle, return 0.
        if (obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][cols - 1] == 1) {
            return 0;
        }

        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        dp[0][0] = 1;

        for (int j = 1; j < cols; ++j) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }

            dp[0][j] = 1;
        }

        for (int i = 1; i < rows; ++i) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }

            dp[i][0] = 1;
        }

        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }

}
