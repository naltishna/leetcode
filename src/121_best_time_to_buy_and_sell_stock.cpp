#include "121_best_time_to_buy_and_sell_stock.h"

namespace _121 {

    /*
    * A single pass through the entire prices is performed exactly once, making time complexity linear regarding the size of the input vector.
    * 
    * Complexity
    * Time complexity:
    * O(N)
    * Space complexity:
    * O(1)
    */
    int Solution::maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = std::min(minPrice, price);
            maxProfit = std::max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }

}