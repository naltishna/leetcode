#include "81_search_in_rotated_sorted_arrayII.h"

namespace _81 {

    /*
    * Modified binary search for a rotated sorted array with possible duplicates.
    * 
    * Time complexity:
    * O(logN)
    * 
    * Space complexity:
    * O(1)
    */
    bool Solution::search(std::vector<int>& nums, int target) {
        if (nums.empty()) return false;

        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Handle duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if (target <= nums[high] && target > nums[mid]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }

}