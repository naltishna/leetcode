#include "322_coin_change.h"

namespace _322 {

    /*
    * Bottom-up DP: dp[amount] = fewest coins to make amount (unreachable if > amount).
    *
    * The algorithm solves the Coin Change Problem by breaking it down into smaller sub-problems
    * (finding the minimum coins for smaller amounts) and reusing those results to build up to the final amount.
    *
    * Time complexity:
    * O(amount * coins.size())
    *
    * Space complexity:
    * O(amount)
    */
    int Solution::coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        const int unreachable = amount + 1;
        std::vector<int> dp(amount + 1, unreachable);
        dp[0] = 0;

        for (int value = 1; value <= amount; ++value) {
            for (int coin : coins) {
                if (coin <= value) {
                    dp[value] = std::min(dp[value], dp[value - coin] + 1);
                }
            }
        }

        const int ans = dp[amount];

        return ans > amount ? -1 : ans;
    }

}
