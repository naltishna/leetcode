#include "18_4sum.h"

#include <algorithm>

namespace _18 {

    /*
    * Sort the array to be able to apply a two-pointers approach.
    * Outer loops iterate through elements of the array selecting the first two points of our potential quadruple.
    * Inner logic using two pointers: left pointer starts right after the second chosen point, the right one begins at the end of the array.
    * Check the sum of currently selected elements. If it matches the target, add this solution to the final result and move both pointers further skipping duplicate numbers.
    * If the sum is greater than the target, shift the right pointer backward; otherwise, we advance the left pointer forward.
    * 
    * Complexity
    * Time complexity:
    * O(N^3)
    * 
    * Space complexity:
    * O(N)
    */
    std::vector<std::vector<int>> Solution::fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> quadruplets;
        size_t end = nums.size();
        if (end < 4) return quadruplets;

        std::sort(nums.begin(), nums.end());

        for (size_t start = 0; start < end - 3; ++start) {
            if (start > 0 && nums[start] == nums[start - 1]) continue;

            for (size_t next = start + 1; next < end - 2; ++next) {
                if (next > start + 1 && nums[next] == nums[next - 1]) continue;

                size_t left = next + 1;
                size_t right = end - 1;
                while (left < right) {
                    long long sum = static_cast<long long>(nums[start]) + nums[next] + nums[left] + nums[right];
                    if (target == sum) {
                        quadruplets.push_back({ nums[start], nums[next], nums[left], nums[right] });

                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (target > sum) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }
        return quadruplets;
    }

}