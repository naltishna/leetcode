#include "35_search_insert_position.h"

namespace _35 {

    /*
     * Binary search.
     *
     * Divide and Conquer: It repeatedly halves the search space by comparing the target with the middle element.
     *
     * Exact Match: If the target is found (nums[middle] == target), it immediately returns its index.
     *
     * Insertion Index: If the target is missing, the loop terminates when left > right.
     * At this exact moment, left points to the correct sorted insertion position.
     *
     * Time complexity:
     * O(log n)
     *
     * Space complexity:
     * O(1)
     */
    int Solution::searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left <= right) {
            const int middle = left + (right - left) / 2;

            if (nums[middle] == target) {
                return middle;
            }

            if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }

        return left;
    }

}