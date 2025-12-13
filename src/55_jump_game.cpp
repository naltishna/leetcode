#include "55_jump_game.h"

namespace _55 {

    /*
    * Greedy algorithm.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    bool Solution::canJump(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return true;
        }

        int maxReach = 0;
        for (int i = 0; i <= maxReach && i < n; ++i) {
            maxReach = std::max(maxReach, i + nums[i]);

            if (maxReach >= n - 1) {
                return true;
            }
        }

        return false;
    }

}