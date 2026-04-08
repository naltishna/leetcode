#include "167_two_sumII_input_array_is_sorted.h"

namespace _167 {

    /*
    * Use two pointers to find a sum. If it matches the target, add indices + 1 to the final result or move both pointers further and repeat steps.
    * 
    * Time complexity:
    * O(N)
    * 
    * Space complexity:
    * O(1)
    */
    std::vector<int> Solution::twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return { left + 1, right + 1 };
            }
            else if (sum > target) {
                --right;
            }
            else {
                ++left;
            }
        }

        return {};
    }

}