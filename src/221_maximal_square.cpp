#include "221_maximal_square.h"

#include <algorithm>
#include <vector>

namespace _221 {

    /*
    * 2D dynamic programming approach.
    *
    * dp[i][j] represents the side length of the largest square of '1's whose bottom-right corner is at position (i, j).
    * For the first row (i == 0) or the first column (j == 0), dp[i][j] is simply 1 if matrix[i][j] == '1',
    * because no larger square can expand beyond the matrix boundaries.
    *
    * If matrix[i][j] == '1', the cell looks at its three neighbors: top (dp[i-1][j]), left (dp[i][j-1]),
    * and top-left (dp[i-1][j-1]). The size of the square is limited by the smallest of these three neighbors.
    *
    * Time complexity:
    * O(m*n) - every cell visited once
    *
    * Space complexity:
    * O(m*n) - full dp table
    */
    int Solution::maximalSquare(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        const int rows = static_cast<int>(matrix.size());
        const int cols = static_cast<int>(matrix[0].size());
        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        int maxSide = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] != '1') {
                    continue;
                }

                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                }

                maxSide = std::max(maxSide, dp[i][j]);
            }
        }

        return maxSide * maxSide;
    }

}
