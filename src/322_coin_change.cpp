#include "322_coin_change.h"
#include "class_version.h"

#include <queue>

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
    template<>
    int Solution<ver1>::coinChange(std::vector<int>& coins, int amount) {
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

    /*
    * Breadth-First Search (BFS) approach.
    *
    * The algorithm uses a queue to explore all possible amounts (from 0 to amount) and
    * tracks which amounts have been visited to avoid infinite loops.
    *
    * Time complexity:
    * O(amount * coins.size())
    *
    * Space complexity:
    * O(amount)
    */
    template<>
    int Solution<ver2>::coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        std::queue<int> q;
        q.push(0);

        std::vector<bool> visited(amount + 1, false);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            steps++;

            for (int i = 0; i < size; ++i) {
                long current = q.front(); // Use long to prevent overflow
                q.pop();

                for (int coin : coins) {
                    long next = current + coin;

                    if (next == amount) return steps;

                    if (next < amount && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }

}