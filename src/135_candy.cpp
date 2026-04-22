#include "135_candy.h"

#include <numeric>

namespace _135 {

    /*
    * Initialize all candies to 1, scan left-to-right to enforce increasing ratings (give +1 when right > left),
    * then scan right-to-left to enforce the opposite and use std::max to avoid overwriting a larger value set in pass 1.
    * The result is the sum of candies.
    * 
    * Time complexity:
    * O(n)
    * 
    * Space complexity:
    * O(n)
    */
    int Solution::candy(std::vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) {
            return n;
        }

        std::vector<int> candies(n, 1);
        for (int i = 0; i + 1 < n; ++i) {
            if (ratings[i] < ratings[i + 1]) {
                candies[i + 1] = candies[i] + 1;
            }
        }

        for (int j = n - 1; j - 1 >= 0; --j) {
            if (ratings[j - 1] > ratings[j]) {
                candies[j - 1] = std::max(candies[j - 1], candies[j] + 1);
            }
        }

        return std::accumulate(candies.begin(), candies.end(), 0);
    }

}