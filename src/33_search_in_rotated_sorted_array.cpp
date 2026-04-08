#include "33_search_in_rotated_sorted_array.h"

namespace _33 {

    /*
    * Modified binary search to identify sorted halves in a rotated array for logarithmic time lookup.
    * 
    * Time complexity:
    * O(logN)
    * 
    * Space complexity:
    * O(1)
    */
    int Solution::search(std::vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        std::size_t low = 0;
        std::size_t high = nums.size() - 1;

        while (low <= high) {
            std::size_t mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }

}