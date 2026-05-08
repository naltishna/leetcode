#include "198_house_robber.h"

#include <algorithm>

namespace _198 {

    /*
    * In-place Dynamic programming.
    *
    * The array is reused in-place as a DP table where nums[i] stores the maximum loot achievable up to house i.
    *
    * At each step the recurrence is:
    * dp[i] = max(dp[i-1], dp[i-2] + nums[i]) - skip house i, rob house i.
    *
    * Either you skip the current house (take the previous best) or you rob it (add its value to
    * the best result two steps back - since adjacent houses can't both be robbed).
    * The answer accumulates to nums[n-1].
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    int Solution::rob(std::vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        nums[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            nums[i] = std::max(nums[i - 1], nums[i - 2] + nums[i]);
        }

        return nums[n - 1];
    }

}