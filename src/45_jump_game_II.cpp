#include "45_jump_game_II.h"
#include "class_version.h"

namespace _45 {

    /*
    * Use greedy approach.
    * 
    * The algorithm finds the minimum number of “maximum long” jumps to cross over the array.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    int Solution<v1>::jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        int steps = 0;
        int lastPos = 0;       // position from the previous jump
        int maxReachPos = 0;   // maximum reachable position from the previous lastPos to the current i

        for (int i = 0; i < n; ++i) {
            if (i > lastPos) {
                steps++;
                lastPos = maxReachPos;

                if (lastPos >= n - 1) {
                    break;
                }
            }

            maxReachPos = std::max(maxReachPos, i + nums[i]);
        }

        return steps;
    }

    /*
    * Use greedy approach.
    * 
    * The algorithm finds the minimum number of “maximum long” jumps to cross over the array.
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    int Solution<v2>::jump(std::vector<int>& nums) {
        size_t n = nums.size();
        if (n <= 1) {
            return 0;
        }

        int steps = 0;
        int currentEnd = 0; // the furthest position from the previous jump
        int farthest = 0;   // the maximum reachable position from the previous currentEnd to the current i

        for (int i = 0; i < n; ++i) {
            farthest = std::max(farthest, i + nums[i]);

            if (i == currentEnd) {
                steps++;
                currentEnd = farthest;

                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }

        return steps;
    }

    /*
    * Use dynamic programming (DP) approach.
    * 
    * The algorithm finds the minimum number of jumps to cross over the array.
    *
    * Time complexity:
    * O(n^2)
    *
    * Space complexity:
    * O(n)
    */
    int Solution<v3>::jump(std::vector<int>& nums) {
        size_t n = nums.size();
        if (n <= 1) {
            return 0;
        }

        constexpr int INF = std::numeric_limits<int>::max();
        std::vector<int> dp(n, INF);
        dp[0] = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (j + nums[j] >= i) {
                    if (dp[j] != INF) {
                        dp[i] = std::min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }

}