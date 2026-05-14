#include "53_maximum_subarray.h"

namespace _53 {

    /*
    * Kadane's algorithm.
    * 
    * The core idea is to find the maximum subarray ending at the current position.
    * At each step, you make a local choice:
    * Extend the existing subarray by adding the current element.
    * Start new from the current element (if the previous sum was negative).
    * 
    * Time complexity:
    * O(n)
    * 
    * Space complexity:
    * O(1)
    */
    int Solution::maxSubArray(std::vector<int>& nums) {
        int result = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            const int num = nums[i];

            currentSum = std::max(num, currentSum + num);
            result = std::max(result, currentSum);
        }

        return result;
    }

}