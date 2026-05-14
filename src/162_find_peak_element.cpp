#include "162_find_peak_element.h"

namespace _162 {

    /*
     * Binary search.
     *
     * Binary search on indices: compare nums[mid] with nums[mid + 1].
     * If nums[mid] > nums[mid + 1], the slope goes down to the right, so some peak lies in [left, mid] (mid may be that peak).
     * Else nums[mid] < nums[mid + 1] (adjacent values differ), the slope goes up to the right, so every peak lies in [mid + 1, right].
     *
     * Time complexity:
     * O(log n)
     *
     * Space complexity:
     * O(1)
     */
    int Solution::findPeakElement(std::vector<int>& nums) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left < right) {
            const int middle = left + (right - left) / 2;

            if (nums[middle] > nums[middle + 1]) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

        return left;
    }

}