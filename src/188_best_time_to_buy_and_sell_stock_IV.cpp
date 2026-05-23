#include "188_best_time_to_buy_and_sell_stock_IV.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace _188 {

    /*
    * Approach: greedy and DP.
    *
    * When k >= n/2, unlimited transactions reduce to a simple greedy (sum all positive daily differences).
    * Otherwise, maintains two arrays buy[t] and sell[t] tracking the best buy cost and max profit for each transaction t,
    * chaining them by offsetting buy[t] against sell[t-1].
    *
    * Time complexity:
    * O(k*n) - n prices * k transactions
    *
    * Space complexity:
    * O(k) - two arrays of size k+1
    */
    int Solution::maxProfit(int k, std::vector<int>& prices) {
        const int n = static_cast<int>(prices.size());
        if (n == 0 || k == 0) {
            return 0;
        }

        // k >= n/2: at most n/2 complete buy-sell pairs fit in n days, so "at most k" is unlimited.
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i) {
                profit += std::max(0, prices[i] - prices[i - 1]);
            }

            return profit;
        }

        std::vector<int> buy(k + 1, INT_MAX);
        std::vector<int> sell(k + 1, 0);

        for (int price : prices) {
            // For each transaction.
            for (int t = 1; t <= k; ++t) {
                // Buy the stock at the lowest price.
                buy[t] = std::min(buy[t], price - sell[t - 1]);
                // Sell the stock at the highest price.
                sell[t] = std::max(sell[t], price - buy[t]);
            }
        }

        return sell[k];
    }

}
