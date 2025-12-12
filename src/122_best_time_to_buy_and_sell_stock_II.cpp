#include "122_best_time_to_buy_and_sell_stock_II.h"

#include <stack>
#include <queue>

namespace _122 {

    /*
    * Multiple Transactions approach - buy a stock whenever the price is expected to rise and sell it immediately as soon as the next higher price is available.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    int Solution::maxProfit(std::vector<int>& prices) {
        int total_profit = 0;

        for (size_t i = 1; i < prices.size(); ++i) {
            total_profit += std::max(0, prices[i] - prices[i - 1]);
        }

        return total_profit;
    }

}