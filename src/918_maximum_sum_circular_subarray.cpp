#include "918_maximum_sum_circular_subarray.h"
#include "class_version.h"

#include <algorithm>
#include <vector>

namespace _918 {

    /*
    * Kadane for max normal subarray (maxSum) and min subarray (minSum) in one pass.
    * Best circular wrap uses the complement: totalSum - minSum, unless all elements
    * are negative (then minSum == totalSum and the wrap would be empty — use maxSum).
    *
    * Time complexity:
    * O(n)
    *
    * Space complexity:
    * O(1)
    */
    template <>
    int Solution<ver1>::maxSubarraySumCircular(std::vector<int>& nums) {
        int currMin = nums[0];
        int currMax = nums[0];
        int minSum = nums[0];
        int maxSum = nums[0];
        int totalSum = nums[0];

        for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
            const int num = nums[i];

            currMax = std::max(num, currMax + num);
            maxSum = std::max(maxSum, currMax);

            currMin = std::min(num, currMin + num);
            minSum = std::min(minSum, currMin);

            totalSum += num;
        }

        // If all numbers are negative, minSum == totalSum and the wrap would be empty. In this case, return maxSum.
        return (minSum == totalSum) ? maxSum : std::max(maxSum, totalSum - minSum);
    }

    /*
    * Enumerate every non-empty circular subarray: each start index s and length L in [1, n]
    * walks s, s+1, … (mod n) without revisiting the same buffer cell (L <= n).
    * No Kadane / complement trick.
    *
    * Time complexity:
    * O(n^2)
    *
    * Space complexity:
    * O(1)
    */
    template <>
    int Solution<ver2>::maxSubarraySumCircular(std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int best = nums[0];

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            // Formula: (i + 1) % n -> (n - 1 + 1) % n -> n % n = 0.
            for (int len = 1; len <= n; ++len) {
                sum += nums[(i + len - 1) % n];
                best = std::max(best, sum);
            }
        }

        return best;
    }

}