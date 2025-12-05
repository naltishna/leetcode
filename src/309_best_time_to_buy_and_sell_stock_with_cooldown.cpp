#include "309_best_time_to_buy_and_sell_stock_with_cooldown.h"

class Buy_and_sell_stock {
public:
    Buy_and_sell_stock() :
        stock_bought(INT_MIN), // INT_MIN, since the purchase requires costs
        stock_sold(0),         // 0, since without any trades the profit is 0
        stock_cooldown(0)      // 0, since we can simply do nothing
    {}

    /* Update states based on the current price. */
    void set_state(int price) {
        int prev_buy_state = stock_bought;
        int prev_sell_state = stock_sold;
        int prev_rest_state = stock_cooldown;

        // 1. Update the buy state (holding the stock)
        // Two options:
        // a) We held the stock yesterday (prev_buy_state) and continue to hold it.
        // b) We were in the 'rest' state yesterday (prev_rest_state) and bought the stock today.
        // The purchase price is subtracted from the profit.
        stock_bought = std::max(prev_buy_state, prev_rest_state - price);

        // 2. Update the sold state (we sold the stock)
        // To sell today, we must have held the stock yesterday (prev_buy_state).
        // Add the current sale price to the previous profit from holding the stock.
        stock_sold = prev_buy_state + price;

        // 3. Update the rest state (resting, cooldown)
        // Two options:
        // a) We were resting yesterday (prev_rest_state) and are still resting.
        // b) We sold the stock yesterday (prev_sell_state), and today we are automatically in the resting state.
        stock_cooldown = std::max(prev_rest_state, prev_sell_state);
    }

    int get_profit() const {
        return std::max(stock_sold, stock_cooldown);
    }

private:
    int stock_bought;
    int stock_sold;
    int stock_cooldown;
};

namespace _309 {

    /*
    * Finite State Machine (FSM): It's difficult to understand and calculate - you just need to correctly describe all possible states.
    *
    * Time complexity:
    * O(N)
    *
    * Space complexity:
    * O(1)
    */
    int Solution::maxProfit(std::vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        Buy_and_sell_stock stock;

        for (int price : prices) {
            stock.set_state(price);
        }

        return stock.get_profit();
    }

}