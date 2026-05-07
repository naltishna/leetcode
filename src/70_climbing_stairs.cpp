#include "70_climbing_stairs.h"

#include <vector>

namespace _70 {

    /*
    * Iterative dynamic programming approach.
    * 
    * Build the solution iteratively from base cases dp[1]=1, dp[2]=2,
    * filling each dp[i] as the sum of the two previous values.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(n)
    */
    int Solution::climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        std::vector<int> dp(n + 1);

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

}