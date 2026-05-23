#include "714_best_time_to_buy_and_sell_stock_with_transaction_fee.h"

#include <algorithm>

namespace _714 {

    /*
    * The algorithm finds the maximum profit by buying and selling the stock at the best possible prices.
    *
    * Greedy approach.
    *
    * Sells whenever profit exceeds the fee, then resets "buyPrice = prices[i] - fee" to allow
    * extending the current trade without double-counting the fee on consecutive profitable days.
    *
    * Time complexity:
    * O(n) - single pass through prices
    *
    * Space complexity:
    * O(1) - only two variables maintained
    */
    int Solution::maxProfit(std::vector<int>& prices, int fee) {
        int profit = 0;
        int buyPrice = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            }
            else if (prices[i] - buyPrice > fee) {
                profit += prices[i] - buyPrice - fee;
                buyPrice = prices[i] - fee; // avoid double-counting fee
            }
        }

        return profit;
    }

}
