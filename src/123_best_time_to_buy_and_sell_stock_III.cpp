#include "123_best_time_to_buy_and_sell_stock_III.h"

#include <algorithm>
#include <climits>

namespace _123 {

    /*
    * Approach: Greedy - 4 State Variables.
    *
    * Simulates two transactions in a single pass using four variables.
    * firstBuy/firstSell track the best first transaction, secondBuy offsets its cost against the first profit,
    * effectively chaining two transactions. secondSell captures the final maximum.
    *
    * Time complexity:
    * O(n) - single pass through prices
    *
    * Space complexity:
    * O(1) - only four variables maintained
    */
    int Solution::maxProfit(std::vector<int>& prices) {
        int firstBuy = INT_MAX;
        int firstSell = 0;
        int secondBuy = INT_MAX;
        int secondSell = 0;

        for (int price : prices) {
            // First transaction.
            // Buy the stock at the lowest price.
            firstBuy = std::min(firstBuy, price);
            // Sell the stock at the highest price.
            firstSell = std::max(firstSell, price - firstBuy);

            // Second transaction.
            // Buy the stock at the lowest price.
            secondBuy = std::min(secondBuy, price - firstSell);
            // Sell the stock at the highest price.
            secondSell = std::max(secondSell, price - secondBuy);
        }

        return secondSell;
    }

}
