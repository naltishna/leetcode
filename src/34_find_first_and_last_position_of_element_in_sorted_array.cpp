#include "34_find_first_and_last_position_of_element_in_sorted_array.h"

namespace _34 {

    /*
    * Binary search.
    *
    * Find the leftmost index of target via lower bound, then find the leftmost index of target + 1 - the last
    * occurrence is one step before it. A single reusable helper replaces two separate search functions.
    *
    * Time complexity:
    * O(log n)
    *
    * Space complexity:
    * O(1)
    */
    std::vector<int> Solution::searchRange(std::vector<int>& nums, int target) {
        const int first = lowerBound(nums, target);
        const int last = lowerBound(nums, target + 1) - 1;

        if (first == static_cast<int>(nums.size()) || nums[first] != target) {
            return { -1, -1 };
        }

        return { first, last };
    }

    int Solution::lowerBound(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size());

        while (left < right) {
            const int mid = left + (right - left) / 2;

            if (nums[mid] < target) left = mid + 1;
            else                    right = mid;
        }

        return left;
    }

}
