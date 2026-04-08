#include "153_find_minimum_in_rotated_sorted_array.h"

#include <algorithm>

namespace _153 {

    /*
    * This approach allows quickly and efficiently finding the minimum in a rotated sorted array by using the binary search.
    * 
    * Time complexity:
    * O(log N)
    * 
    * Space complexity:
    * O(1)
    */
    int Solution::findMin(std::vector<int>& nums) {
        if (nums.empty()) return -1;

        int low = 0;
        int high = nums.size() - 1;
        int min = nums[0];

        while (low <= high) {
            if (nums[low] <= nums[high]) {
                min = std::min(min, nums[low]);
                break;
            }

            int mid = low + (high - low) / 2;
            min = std::min(min, nums[mid]);

            if (nums[low] <= nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return min;
    }

}